
%{
#include"CMINUS.h"
#include"tree.h"

void yyerror(char *);
int yylex();

extern int yylineno;
struct Node *cldArray[10];
int cldN;
int nTag;

%}

%union{
	struct Node * val;
	int vali;
	float valf;
}

%token <vali>INT 					// 258
%token <valf>FLOAT					// 259
%token <val>ID						// 260
%token <val>SEMI COMMA 				// 261 262	
%token <val>ASSIGNOP	
%token <val>RELOP					// 我觉得这个得展开，但暂时忽略	
%token <val>PLUS MINUS STAR DIV		// 265
%token <val>AND OR NOT
%token <val>DOT
%token <val>TYPE
%token <val>LP RP
%token <val>LB RB
%token <val>LC RC
%token <val>STRUCT
%token <val>RETURN
%token <val>IF ELSE
%token <val>WHILE
%token <val>FNCT
%token <val>ERRORA;

%token <val>EPS

%type <val> Exp


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
	| Exp LB Exp error RB 		{printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	| Exp DOT ID 				{}
	| ID 						{}
	| INT 						{}
	| FLOAT 					{}
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