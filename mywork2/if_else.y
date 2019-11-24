%{
// if_then_else
#define YYSTYPE int
#include <ctype.h>
#include<stdio.h>
void yyerror(char*);
int yylex();

%}

%token IF
%token THEN 
%token ELSE

%% 
input:		/*empty equal to epsilon*/
	| input line
	;
line: '\n'
	| stat '\n'		{printf("parser success\n");}
	;
stat: exp
	| IF exp THEN exp
	| IF exp THEN exp ELSE exp
	;

%%
int yylex(){
	int c;
	/*skip white space*/
	while((c=getchar())==' '||c=='\t')
		;
	/*process numbers*/
	if(isdigit(c)){
		ungetc(c, stdin);
		scanf("%d",&yylval);
		return NUM;
	}
	if(c==EOF) 
		return 0;
		
	return c;
}

int main(void){
	int n=yyparse();
	printf("%d",n);
	return n;
}

void yyerror(char*s){
	printf("%s\n",s);
}