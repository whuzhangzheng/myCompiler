%{
// 逆波兰表达式的计算
// #define YYSTYPE int
// #include <ctype.h>
#include<stdio.h>

void yyerror(char*);
int yylex();
%}

%token NUM
%token ADD SUB MUL DIV
%token EOL

%% 
input:		/*empty equal to epsilon*/
	| input line
	;
line: EOL
	| exp EOL	{printf("\%d\n",$1);}
	;
exp: NUM	{$$ = $1;}
	| exp exp ADD 	{$$ = $1+$2;}
	| exp exp SUB	{$$ = $1-$2;}
	| exp exp MUL 	{$$ = $1*$2;}
	| exp exp DIV 	{$$ = $1 / $2;}
	;
%%


int main(void){ 
	int n=yyparse();
	printf("%d",n);
	return n;
}

void yyerror(char*s){
	printf("%s\n",s);
}