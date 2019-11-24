%{ 
#include "calc.h" /* ����ϵͳ����ͷ�ļ�*/ 
#define YYDEBUG 1 /* ������Դ��� */ 
#define YYDEBUG_LEXER_TEXT lexeme /* ����ʱ�������ǰ�鿴�Ĵ��� */ 
char lexeme[80]; 
%} 

%union { 
	double val; /* ���ʽ������ֵ */ 
	SYMREC *tptr; /* �����ͺ���������ֵ�Ƿ��ű�Ԫ��ָ�� */ 
} 
%token<val> NUM /* ����ֵ��������˫���ȸ����� */ 
%token<tptr> VAR FNCT /* ����ֵ�������Ƿ��ű�Ԫ��ָ�� */ 
%type<val> exp 

 /* �����ϴ�������ȼ��� */ 

%right '=' 
%left '-' '+' 
%left '*' '/' 
%left NEG /* ����ʻ㣬��һԪ��ͬ�� */ 
%right '^' /* ָ������ */

%% /* �﷨���򲿷� */ 
input: /* �մ� */ 
	| input line 
	; 
line: '\n' 
	| exp '\n' { printf("\t%.10g\n", $1); } 
	| error '\n' { yyerrok; } 
	;
exp: NUM { $$ = $1; } 
	| VAR { $$ = $1->value.var; } 
	| VAR '=' exp { $$ = $3; $1->value.var = $3; } 
	| FNCT '(' exp ')' { $$ = (*($1->value.fnctptr))($3); } 
	| exp '+' exp { $$ = $1 + $3; } | exp '-' exp { $$ = $1 - $3; } 
	| exp '*' exp { $$ = $1 * $3; } | exp '/' exp { $$ = $1 / $3; } 
	| '-' exp %prec NEG { $$ = -$2; } | exp '^' exp { $$ = pow ($1, $3); } 
	| '(' exp ')' { $$ = $2; } 
	; 

%% 
void yyerror(const char *s) {
	fprintf(stderr, "%s", s); 
} /* �����ṩ */
