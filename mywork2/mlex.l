
%{
#include<stdio.h>
// ×Ö·ûÍ³¼Æ³ÌĞò
int strlen(char*);
int chars = 0;
int words = 0;
int lines = 0;
%}
%%
[a-zA-Z]+  	{words++;  chars += strlen(yytext);}
\n			{lines++;}
.			{chars++;}
<<EOF>>		{printf("eof"); return 0;}
%%
int main(){
	yylex();
	printf("lines: %d,  words: %d,  chars: %d\n",lines, words, chars);
	return 0;
}