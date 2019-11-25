%{
# include "fb1-5.tab.h"

%}

%%
"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }
"|"     { return ABS; }
"("     { return OP; }
")"     { return CP; }
[0-9]+	{ yylval = atoi(yytext); return NUMBER; }
0[xX][0-9a-fA-F]*	{char*ptr; yylval = strtol(yytext,&ptr, 16); return NUMBER;}

\n      { return EOL; }
"//".*  
[ \t]   { /* ignore white space */ }
.	{ printf("Mystery character %c\n", *yytext); }
%%
