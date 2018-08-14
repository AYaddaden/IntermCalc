# Part 3 of TP COMPIL

Generating intermediate form for a calculator

Program written on Ubuntu 17.10 LTS using flex and bison

To compile:

```
bison -d compil.y

flex compil.l

gcc -o compil compil.tab.c lex.yy.c -lfl -lm
```
