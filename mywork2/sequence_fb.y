%{
#include<stdio.h>

void yyerror(char*);
int yylex();
%}

%token WORD
%token EOL


%%
input:
	| sequence EOL
	;
sequence:	{printf("empty sequence\n");}
	|	maybeword
	| sequence WORD {printf("add new word\n"); }
	;
	
maybeword:	{printf("empty maybeword\n");}
	|	WORD	{printf("single word \n");}
	;
%%

int main(void){
	return yyparse();
}

void yyerror(char*s){
	printf("%s\n",s);
}