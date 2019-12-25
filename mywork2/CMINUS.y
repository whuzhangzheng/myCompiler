
%{
#include"CMINUS.h"

void yyerror(char *);
int yylex();

extern int yylineno;
%}

%union{
	int vali;
	float valf;
	SYMREC *tptr;
	int type;
	EXPVAL expval;
}

%token <vali> INT 					// 258
%token <valf> FLOAT					// 259
%token <tptr> ID						// 260
%token <type> SEMI COMMA 				// 261 262	
%token <type> ASSIGNOP	
%token <type> RELOP					// 我觉得这个得展开，但暂时忽略	
%token <type> PLUS MINUS STAR DIV		// 265
%token <type> AND OR NOT
%token <type> DOT
%token <type> TYPE
%token <type> LP RP
%token <type> LB RB
%token <type> LC RC
%token <type> STRUCT
%token <type> RETURN
%token <type> IF ELSE
%token <type> WHILE
%token FNCT
%token ERRORA;

%type <expval> Exp


%%

Program : ExtDefList 			{}
ExtDefList :	/*定义列表*/	{}
	| ExtDef ExtDefList 		{}
	;	 
ExtDef : Specifier ExtDecList SEMI	{} 
	| Specifier SEMI 			{}
	| Specifier FunDec CompSt 	{}
	;
ExtDecList : VarDec 			{}
	| VarDec COMMA ExtDecList	{}
	;
Specifier : TYPE 				{}
	| StructSpecifier 			{}
	;
StructSpecifier : STRUCT OptTag LC DefList RC	{} 
	| STRUCT Tag 				{}
	;
OptTag :  						{}
	| ID						{}
	;
Tag : ID						{}
	;
VarDec : ID 					{}
	| VarDec LB INT RB			{}
	| VarDec LB INT error RB	{printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	;
FunDec : ID LP VarList RP 		{}
	| ID LP RP 					{}
	;
VarList : ParamDec COMMA VarList {}
	| ParamDec 					{}
	;
ParamDec : Specifier VarDec		{}
	;
CompSt : LC DefList StmtList RC {}
	;
StmtList : 						{/* \epsilon */}
	| Stmt StmtList 			{}
	;
Stmt : Exp SEMI 				{}
	| Exp error SEMI 			{printf("Error Type B at Line %d: Missing \";\"\n", yylineno);}
	| CompSt 					{}
	| RETURN Exp SEMI 			{}
	| IF LP Exp RP Stmt 		{}
	| IF LP Exp RP Stmt ELSE Stmt	{} 
	| WHILE LP Exp RP Stmt 		{}
	;
DefList : 						{}
	|Def DefList 				{}
	;
Def : Specifier DecList SEMI 	{}
	;
DecList : Dec 					{}
	| Dec COMMA DecList 		{}
	;
Dec : VarDec 					{}
	| VarDec ASSIGNOP Exp 		{}
	| VarDec ASSIGNOP error Exp 		{}
	;
	
// 表达式
Exp : Exp ASSIGNOP Exp 			{$$.type = $3.type; }
	| Exp AND Exp 				{}
	| Exp OR Exp 				{}
	| Exp RELOP Exp 			{}
	| Exp PLUS Exp 				{$$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali + $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)+(($3.type==INT)?$3.value.vali:$3.value.valf);
								}
	| Exp MINUS Exp 			{$$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali - $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)-(($3.type==INT)?$3.value.vali:$3.value.valf);
								}
	| Exp STAR Exp 				{$$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali * $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)*(($3.type==INT)?$3.value.vali:$3.value.valf);
								}
	| Exp DIV Exp 				{$$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali / $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)/(($3.type==INT)?$3.value.vali:$3.value.valf);
								}
	| LP Exp RP 				{}
	| MINUS Exp 				{}
	| NOT Exp 					{}
	| ID LP Args RP 			{}
	| ID LP RP 					{}
	| Exp LB Exp RB 			{}
	| Exp LB Exp error RB 		{printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	| Exp DOT ID 				{}
	| ID 						{}
	| INT 						{$$.type = INT; $$.value.vali = $1;}
	| FLOAT 					{$$.type = FLOAT; $$.value.valf = $1;}
	;
Args : Exp COMMA Args 	// 参数
	| Exp
	;
%%


int main(int argc, char** argv){
	FILE*f;
	if(argc > 1){
		if(!(f=fopen(argv[1],"r"))){
			perror(argv[1]);
			return 1;
		}
		yyrestart(f);
	}
	yylineno = 1;
	yyparse();
	
	return 0;
}

void yyerror(char*s){
	//char type = 'A';
	//printf("Error type %c at Line %d: %s\n",type, yylineno, s);
}