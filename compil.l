%{

#include "compil.tab.h"
#include <stdlib.h>
#include <string.h>
%}

white [ \t]+
digit [0-9]
integer {digit}+
real {integer}("."{integer})?
symbol [a-zA-Z]+
%%

{white} { }

"moyenne" return MOYENNE;
"somme" return SOMME;
"produit" return PRODUCT;
"variance" return VARIANCE;
"ecart-type" return ECARTTYPE ;
"max" return MAX;
, return COMMA;
"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"/" return DIVIDE;
"^" return POWER;
"(" return LEFT;
")" return RIGHT;
"\n" return END;
"exit" return EXIT;

{symbol}{integer}? { strcpy(yylval.value,yytext); 
 return NUMBER;
}
{real} {  
	sprintf(yylval.value,"%s",yytext);
 return NUMBER;
}
%%

int yywrap(void){return 1;}
