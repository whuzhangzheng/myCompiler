%{
// 逆波兰表达式的计算
#define YYSTYPE int
#include <ctype.h>
#include<stdio.h>
void yyerror(char*);
int yylex();
%}

%token NUM

%% 
input:		/*empty equal to epsilon*/
	| input line
	;
line: '\n'
	|exp '\n'	{printf("\%.d\n",$1);}
	;
exp: NUM	{$$ = $1;}
	| exp exp '+' 	{$$ = $1+$2;}
	| exp exp '-'	{$$ = $1-$2;}
	| exp exp '*' 	{$$ = $1*$2;}
	| exp exp '/' 	{$$ = $1 / $2;}
	| exp 'n'	{$$ = -$1; }
	;
%%
int yylex(){
	int c;
	/*skip white space*/
	while((c=getchar())==' '||c=='\t')
		;
	//printf("%c",c);
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