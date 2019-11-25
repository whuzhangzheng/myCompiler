%{
#  include <stdio.h>

int yylex(void);
void yyerror(char *s);
extern FILE* yyin;

%}

/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token OP CP
%token EOL

%%

calclist: /* nothing */
 | calclist exp EOL { printf("= %d\n> ", $2); }
 | calclist EOL { printf("> "); } /* blank line or a comment */
 ;

exp: factor
 | exp ADD factor { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 | exp ABS factor { $$ = $1 | $3; }
 ;

factor: term
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: NUMBER
 | ABS term { $$ = $2 >= 0? $2 : - $2; }
 | OP exp CP { $$ = $2; }
 ;
%%
int main(int argc, char **argv)
{
	FILE* f;
	if(argc>1){
		if(!(f = fopen(argv[1], "r"))){
			perror(argv[1]);
			return 1;
		}
		yyrestart(f);
	}
	printf("> "); 
	yyparse();
	return 0;
}

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
