
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

%type <EXPVAL> Exp


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
StmtList : 						{}
	| Stmt StmtList 			{}
	;
Stmt : Exp SEMI 				{}
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
	;
	
// 表达式
Exp : Exp ASSIGNOP Exp 			{}
	| Exp AND Exp 				{}
	| Exp OR Exp 				{}
	| Exp RELOP Exp 			{}
	| Exp PLUS Exp 				{}
	| Exp MINUS Exp 			{}
	| Exp STAR Exp 				{}
	| Exp DIV Exp 				{}
	| LP Exp RP 				{}
	| MINUS Exp 				{}
	| NOT Exp 					{}
	| ID LP Args RP 			{}
	| ID LP RP 					{}
	| Exp LB Exp RB 			{}
	| Exp DOT ID 				{}
	| ID 						{}
	| INT 						{}
	| FLOAT 					{}
	;
Args : Exp COMMA Args 	// 参数
	| Exp
	;
%%

void yyerror(char*s){
	char type = 'A';
	printf("Error type %c at Line %d: %s\n",type, yylineno, s);
}