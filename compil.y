%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
FILE* destination;
int dest = 0;
struct node {
    char data[50];
    struct node* next;
};

struct linked_list {
    struct node* start;
    struct node* end;
};

typedef struct Quad {
		char op[50];
		char src1[50];
		char src2[50];
		char dest[50];
}Quad;


int quadCourant =0, cpt_tmp=1;
char buf[50], buf1[50], buf2[50], buf3[50];
Quad quad[100]; 


int isError = 0; //0: there is no error so print result; 1: there is an error so don't print
int isFile = 0; //0: we read from an stdin; 1: we read from a file specified in argument

void GenererQuadruplet(char CodeOp[50],char source1[50],char source2[50],char destination[50]);
void empilerQuad(Quad tab[] ,Quad val,int* ptr);
Quad depilerQuad (Quad tab[] ,int *ptr);

char* moyenne(struct linked_list* list);
char* somme(struct linked_list* list);
char* produit(struct linked_list* list);
char* variance(struct linked_list* list);
char* racine(char* a);
char* ecartType(struct linked_list* list);
char* max(struct linked_list* list);
int yyerror(char *err);
int yylex();
%}


%union{
	char value[20]; //for operands
	char symbol; //for operators
	char* string; //for functions
	int num;
	struct linked_list* list; //for function's arguments
}


%token <value>  NUMBER
%token <symbol> PLUS MINUS TIMES DIVIDE POWER
%token <symbol> LEFT RIGHT
%token <string> EXIT MOYENNE SOMME PRODUCT VARIANCE ECARTTYPE MAX
%token <symbol> COMMA 
%token <symbol> END


%left PLUS MINUS
%left TIMES DIVIDE
%left MODUL
%left NEG POS
%right POWER

%type <value> Expression Input Function
%type <list> List
%type <num> Name

%start Input
%%

Input:	/*empty*/ { if (!isFile) printf("> ");}
      | Input Line
;

Line:
     END { if (!isFile) printf("> ");}
     | Expression END { if (!isError){
     					if(dest ==1) //on ecrit dans un fichier
     					{
     						int i=0;
     						fprintf(destination,"   Op\t|Src1\t|Src2\t|Dest \n");
     						for(i=0;i<quadCourant;i++){
     							fprintf(destination,"%2d: %s\t| %s\t| %s\t| %s\n",i,quad[i].op,quad[i].src1,quad[i].src2, quad[i].dest);
    			
     						}
     						fprintf(destination,"----------------------------------\n");
     						
     					}else{
     						int i=0;
     						printf("   Op\t|Src1\t|Src2\t|Dest \n");
     						for(i=0;i<quadCourant;i++){
     							printf("%2d: %s\t| %s\t| %s\t| %s\n",i,quad[i].op,quad[i].src1,quad[i].src2, quad[i].dest);
    			
     						}
     						//quadCourant = 0;
     						//cpt_tmp = 1;
     						


     					}	
     					quadCourant = 0;
     					cpt_tmp = 1;
     					isError = 0;
     					if (!isFile) printf("> "); 
     					}
     				}
     | EXIT { exit(EXIT_SUCCESS);}
;

Expression:
     NUMBER { strcpy($$,$1); }
	| Expression PLUS Expression { 
			sprintf(buf,"%s",$1);
			sprintf(buf1,"%s",$3);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			GenererQuadruplet("+",buf,buf1,buf2);
	
	
	 }
	| Expression PLUS error { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
	| PLUS Expression %prec POS { strcpy($$,$2); }
	| Expression MINUS Expression { 
	
			sprintf(buf,"%s",$1);
			sprintf(buf1,"%s",$3);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			GenererQuadruplet("-",buf,buf1,buf2);
	
	
	}
	| Expression MINUS error { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
	| Expression TIMES Expression { 
			sprintf(buf,"%s",$1);
			sprintf(buf1,"%s",$3);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			GenererQuadruplet("*",buf,buf1,buf2);
	
	
	 }
	| Expression TIMES error { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
	| Expression DIVIDE Expression { 
				if(strcmp($3,"0")==0) 
				{
					yyerror("Erreur! Division par 0\n");
					isError = 1;
				}
				else{
					sprintf(buf,"%s",$1);
					sprintf(buf1,"%s",$3);
					sprintf(buf2,"%s%d","tmp",cpt_tmp);
					sprintf($$,"%s%d","tmp",cpt_tmp);
					cpt_tmp++;
					GenererQuadruplet("/",buf,buf1,buf2);
	
				} 
			}
	| Expression DIVIDE error {  yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
	| MINUS Expression %prec NEG { 
	
					sprintf(buf,"%d",-1);
					sprintf(buf1,"%s",$2);
					sprintf(buf2,"%s%d","tmp",cpt_tmp);
					sprintf($$,"%s%d","tmp",cpt_tmp);
					cpt_tmp++;
					GenererQuadruplet("*",buf,buf1,buf2);
	
	 }
	| Expression POWER Expression { 
	
					sprintf(buf,"%s",$1);
					sprintf(buf1,"%s",$3);
					sprintf(buf2,"%s%d","tmp",cpt_tmp);
					sprintf($$,"%s%d","tmp",cpt_tmp);
					cpt_tmp++;
					GenererQuadruplet("^",buf,buf1,buf2);
	
	 }
	| Expression POWER error { yyerror("Opérande attendue\n"); yyerrok; isError = 1;}
	| LEFT Expression RIGHT { strcpy($$,$2); }
	| LEFT Expression error { yyerror("')' attendue\n"); yyerrok; isError = 1;}
	| Function { strcpy($$,$1);	}

;

Function: Name LEFT List RIGHT{
			struct linked_list* list = $3;
			int numFunction = $1;
			if(list)
			{
				switch (numFunction)
				{
					case 1: //si c'est la moyenne
						strcpy($$,moyenne(list));
						break;
				
					case 2: //si c'est la somme
						strcpy($$,somme(list));
						break;
					case 3: //si c'est le produit
						strcpy($$,produit(list));
						break;
					case 4: //si c'est la variance
						strcpy($$,variance(list));
						break;
					case 5: //si c'est l'ecart type
						strcpy($$,ecartType(list));
						break;
					case 6:
						strcpy($$,max(list));
						break;
				}
			} 
			
		}
		| Name error List RIGHT { yyerror("'(' attendue\n"); yyerrok; isError =1;}
		| Name LEFT List error { yyerror("')' attendue\n"); yyerrok; isError =1;}
		
;

Name: MOYENNE { $$ = 1;}
	| SOMME { $$ = 2;}
	| PRODUCT { $$ = 3;}
	| VARIANCE { $$ = 4;}
	| ECARTTYPE { $$ = 5;}
	| MAX {$$ = 6;}
;

List: List COMMA Expression {
		if(!isError){
			struct node* node = malloc(sizeof(struct node)); 
		    strcpy(node->data,$3);
		    node->next = NULL;
		    struct linked_list* list = $1;
		    list->end->next = node;
		    list->end = node;

		    $$ = list;
		}
        
	}
	| Expression {
		if(!isError){
			struct linked_list* list = malloc(sizeof(struct linked_list));
		 	struct node* node = malloc(sizeof(struct node));

			strcpy(node->data , $1);
			node->next = NULL;
			list->start = node;
			list->end = node;
			$$ = list;
		}
	    
	}
	| error COMMA Expression { yyerror("Argument attendu avant ','\n"); yyerrok; isError = 1;}
	| List COMMA error { yyerror("Argument attendu apres ','\n"); yyerrok; isError = 1;}
	
;
	
%%

int yyerror(char *err) {
  fprintf(stderr,"%s\n", err);
}


int main(int argc, char* argv[]) {

  if (argc>1){
  	if(strcmp(argv[1],"-f")==0)
  	{
  		if(argv[2])
  		{
  			destination = fopen(argv[2],"w");
  		
  		} else destination = fopen("formeIntermediaire.txt","w");
  		if(destination != NULL)
  		{
  			dest =1;
  			yyparse();
  			fclose(destination);
  		}
  		else
  		{
  		 printf("Impossible d'ouvrir le fichier formeIntermediaire.txt\nPassage en mode console");
  		 dest = 0;
  		 yyparse();
  		}
  	}else
  	{
  		yyin = fopen(argv[1],"r");
  		if (yyin != NULL)
  		{
  			isFile = 1;
  			yyparse();
  			fclose(yyin);
  			return 0;
  		}
  		else printf("Impossible d'ouvrir le fichier %s\n",argv[1]);
	}
  }
  else 
  {
  	return yyparse();
  }
}


char* somme(struct linked_list* list)
{
	struct node* node = list->start;
	if ((node != NULL)&&(node->next !=NULL))
	{
		sprintf(buf,"%s",node->data);
		sprintf(buf1,"%s",node->next->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("+",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		
		node = node->next->next;
		
	}
	while(node != NULL)
	{
		sprintf(buf1,"%s",node->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("+",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		node = node->next;	
	}
	return buf;
}

char* produit(struct linked_list* list)
{
	struct node* node = list->start;
	if ((node != NULL)&&(node->next !=NULL))
	{
		sprintf(buf,"%s",node->data);
		sprintf(buf1,"%s",node->next->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("*",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		
		node = node->next->next;
		
	}
	while(node != NULL)
	{
		sprintf(buf1,"%s",node->data);
		sprintf(buf2,"%s%d","tmp",cpt_tmp);
		GenererQuadruplet("*",buf,buf1,buf2);
		sprintf(buf,"%s%d","tmp",cpt_tmp);
		cpt_tmp++;
		node = node->next;	
	}
	return buf;
}

char* moyenne(struct linked_list* list)
{
	struct node* node = list->start;
	int cpt;
	if(node){
		if(node->next == NULL)
		{
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s","");
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("+",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
		}
		else
		{
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->next->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("+",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			node = node->next->next;
			cpt = 2;
			while(node != NULL)
			{
				sprintf(buf1,"%s",node->data);
				sprintf(buf2,"%s%d","tmp",cpt_tmp);
				GenererQuadruplet("+",buf,buf1,buf2);
				sprintf(buf,"%s%d","tmp",cpt_tmp);
				cpt_tmp++;
				cpt++;
				node = node->next;	
				
			}
			sprintf(buf1,"%d",cpt);	
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("/",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
				
		}
		
	
	}
	return buf;
}

char* variance(struct linked_list* list)
{
	struct node* node = list->start;
	int cpt;
	if(node){
		if(node->next == NULL)
		{
			//X2
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			//X
			sprintf(buf1,"%s",node->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("-",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
		}
		else
		{
			//Moment d'ordre 2
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			sprintf(buf1,"%s",node->next->data);
			sprintf(buf2,"%s",node->next->data);
			sprintf(buf3,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf1,buf2,buf3);
			sprintf(buf3,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("+",buf,buf3,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
				
			
			node = node->next->next;
			cpt = 2;
			
			while(node != NULL)
			{
				sprintf(buf1,"%s",node->data);
				sprintf(buf3,"%s",node->data);
				sprintf(buf2,"%s%d","tmp",cpt_tmp);
				cpt_tmp++;
				GenererQuadruplet("*",buf1,buf3,buf2);
				sprintf(buf3,"%s%d","tmp",cpt_tmp);
				GenererQuadruplet("+",buf,buf2,buf3);
				sprintf(buf,"%s%d","tmp",cpt_tmp);
				cpt_tmp++;
				cpt++;
				node = node->next;	
				
			}
			
			//La somme / N
			sprintf(buf1,"%d",cpt);	
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("/",buf,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			//Moyenne
			sprintf(buf3,"%s",buf);
			sprintf(buf1,"%s",moyenne(list));	
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("*",buf1,buf1,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			//E(x2)-E(x)2
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("-",buf3,buf,buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
				
		}
		
	
	}
	return buf;

}

char* racine(char* a)
{
	char val[50];
	char quadRetour[50];
	
	sprintf(val,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	
	sprintf(buf1,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	
	
	GenererQuadruplet("MOV","1","",val);	
	sprintf(quadRetour,"%d",quadCourant+1);
	GenererQuadruplet("MOV",val,"",buf1);
	sprintf(buf2,"%s%d","tmp",cpt_tmp);
	GenererQuadruplet("/",a,buf1,buf2);
	cpt_tmp++;
	sprintf(buf3,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	GenererQuadruplet("+",buf1,buf2,buf3);
	sprintf(buf2,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	GenererQuadruplet("/",buf3,"2",buf2);
	sprintf(buf3,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	GenererQuadruplet("MOV",buf1,"",buf3);
	GenererQuadruplet("MOV",buf2,"",buf1);
	GenererQuadruplet("SUB",buf3,buf1,"");
	GenererQuadruplet("JNZ","","",quadRetour);
	return buf1;		
}

char* ecartType(struct linked_list* list)
{
	char a[50];
	
	sprintf(a,"%s%d","tmp",cpt_tmp);
	cpt_tmp++;
	strcpy(a,variance(list));
	return racine(a);
	
}

char* max(struct linked_list* list)
{
	struct node* node = list->start;
	
	if(node){
		if(node->next)
		{
			sprintf(buf,"%s",node->data);
			sprintf(buf1,"%s",node->next->data);
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			GenererQuadruplet("CMP",buf,buf1,"");
			sprintf(buf3,"%d",quadCourant+3);
			GenererQuadruplet("JL","","",buf3);
			GenererQuadruplet("MOV",buf,"",buf2);
			sprintf(buf3,"%d",quadCourant+2);
			GenererQuadruplet("JMP","","",buf3);
			GenererQuadruplet("MOV",buf1,"",buf2);
			sprintf(buf,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			
			node = node->next->next;

			while(node != NULL)
			{
				sprintf(buf1,"%s",node->data);
				GenererQuadruplet("CMP",buf,buf1,"");
				sprintf(buf3,"%d",quadCourant+2);
				GenererQuadruplet("JL","","",buf3);
				sprintf(buf3,"%d",quadCourant+2);
				GenererQuadruplet("JMP","","",buf3);
				GenererQuadruplet("MOV",buf1,"",buf);
				
				node = node->next;	
				
			}
				
		}
		
	
	}
	return buf;
}

void GenererQuadruplet(char CodeOp[50],char source1[50],char source2[50],char destination[50]){
	strcpy(quad[quadCourant].op,CodeOp);
	strcpy(quad[quadCourant].src1,source1);
	strcpy(quad[quadCourant].src2,source2);
	strcpy(quad[quadCourant].dest,destination);
	quadCourant++;
}

void empilerQuad(Quad tab[] ,Quad val,int* ptr){
	*ptr = *ptr + 1;
	strcpy(tab[*ptr].op , val.op );
	strcpy(tab[*ptr].src1 ,val.src1) ;
	strcpy(tab[*ptr].src2 , val.src2); 
	strcpy(tab[*ptr].dest , val.dest) ;
}
	
Quad depilerQuad (Quad tab[] ,int *ptr){
	Quad quad = tab[*ptr];
	*ptr = *ptr - 1;
	return quad;
}	

