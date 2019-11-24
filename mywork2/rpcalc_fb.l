
%{
#include "rpcalc_fb.tab.h"

%}

%%
"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }

[0-9]+	{ yylval = atoi(yytext); return NUM; }

\n      { return EOL; }
"//".*  
[ \t]   { /* ignore white space */ }
.	{ printf("Mystery character %c\n", *yytext); }
%%