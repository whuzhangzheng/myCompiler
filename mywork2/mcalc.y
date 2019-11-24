%{ 
#include "calc.h" /* 包含系统定义头文件*/ 
#define YYDEBUG 1 /* 激活调试代码 */ 
#define YYDEBUG_LEXER_TEXT lexeme /* 调试时输出的向前查看的词形 */ 
char lexeme[80]; 
%} 

%union { 
	double val; /* 表达式的语义值 */ 
	SYMREC *tptr; /* 变量和函数的语义值是符号表元素指针 */ 
} 
%token<val> NUM /* 语义值的类型是双精度浮点数 */ 
%token<tptr> VAR FNCT /* 语义值的类型是符号表元素指针 */ 
%type<val> exp 

 /* 定义结合次序和优先级别 */ 

%right '=' 
%left '-' '+' 
%left '*' '/' 
%left NEG /* 虚拟词汇，和一元减同级 */ 
%right '^' /* 指数函数 */

%% /* 语法规则部分 */ 
input: /* 空串 */ 
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
} /* 必须提供 */
