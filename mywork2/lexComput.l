%{
// 表达式识别
#include<stdio.h>
enum yytokentype {
     NUMBER = 258,
     ADD = 259,
     SUB = 260,
     MUL = 261,
     DIV = 262,
     ABS = 263,
     EOL = 264 /* end of line */
   };
int yylval;
   
%}
%%
"+"		{ECHO; return ADD;}
"-"		{ECHO; return MUL;}
"*"		{ECHO; return MUL;}
"/"		{ECHO; return DIV;}
"|"     {ECHO; return ABS; }
\n		{ECHO; return EOL;}
[ \t]   { /* ignore white space */ }
[0-9]+	{ECHO; yylval = atoi(yytext); return NUMBER;}


%%

int main(){
	int tok;
	while(tok=yylex()){
		if(tok==NUMBER){
			printf("number:%d\n",yylval);
		}else{
			printf("%d\n",tok);
		}
	}
	return 0;
}