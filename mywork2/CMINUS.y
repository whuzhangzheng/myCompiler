
%{
#include"CMINUS.h"

void yyerror(char *);
int yylex();
void toGramTree(char *name);

extern int yylineno;
int err=0;
char gramTree[10000]="";
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

Program : 	{toGramTree("Program")} 	ExtDefList 			
ExtDefList:	{}
	| 		{toGramTree("ExtDefList");} 	ExtDef ExtDefList 		
	;	 
ExtDef: {toGramTree("ExtDef");}  	Specifier ExtDecList SEMI	{}
	| 	{toGramTree("ExtDef");}		Specifier SEMI 				{}
	| 	{toGramTree("ExtDef");}		Specifier FunDec CompSt 	{}
	;
ExtDecList : {toGramTree("ExtDecList");}	VarDec 			{}
	| 		{toGramTree("ExtDecList");}  	VarDec COMMA ExtDecList	{}
	;
Specifier : {toGramTree("Specifier");}	TYPE 				{}
	| 		{toGramTree("Specifier");}		StructSpecifier 			{}
	;
StructSpecifier : STRUCT OptTag LC DefList RC	{} 
	| STRUCT Tag 				{}
	;
OptTag :  						{}
	| ID						{}
	;
Tag : ID						{}
	;
VarDec : {toGramTree("VarDec");} 	ID 					{}
	| {toGramTree("VarDec");}		VarDec LB INT RB			{}
	| {toGramTree("VarDec");}		VarDec LB INT error RB	{err = 1;printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	;
FunDec: {toGramTree("FunDec");} ID LP VarList RP 		{}
	| {toGramTree("FunDec");}	ID LP RP 					{}
	;
VarList : ParamDec COMMA VarList {}
	| ParamDec 					{}
	;
ParamDec : Specifier VarDec		{}
	;
CompSt : {toGramTree("CompSt");}		LC DefList StmtList RC {}
	;
StmtList : 						{/* \epsilon */}
	|{toGramTree("StmtList");} Stmt StmtList 			{}
	;
Stmt : {toGramTree("Stmt");} 	Exp SEMI 				{}
	| {toGramTree("Stmt");}		Exp error SEMI 			{err=1; printf("Error Type B at Line %d: Missing \";\"\n", yylineno);}
	| {toGramTree("Stmt");}		CompSt 					{}
	| {toGramTree("Stmt");}		RETURN Exp SEMI 			{}
	| {toGramTree("Stmt");}		IF LP Exp RP Stmt 		{}
	| {toGramTree("Stmt");}		IF LP Exp RP Stmt ELSE Stmt	{} 
	| {toGramTree("Stmt");}		WHILE LP Exp RP Stmt 		{}
	;
DefList : 						{}
	|{toGramTree("DefList");}		Def DefList 				{}
	;
Def : {toGramTree("Def");}			Specifier DecList SEMI 	{}
	;
DecList : {toGramTree("DecList");} 	Dec 					{}
	| {toGramTree("DecList");}		Dec COMMA DecList 		{}
	;
Dec : {toGramTree("Dec");}VarDec 					{}
	| {toGramTree("Dec");}VarDec ASSIGNOP Exp 		{}
	| {toGramTree("Dec");}VarDec ASSIGNOP error Exp 		{err=1;}
	;
	
// 表达式
Exp : {toGramTree("Exp");}		Exp ASSIGNOP Exp 			{/*$$.type = $3.type; */}
	| {toGramTree("Exp");}	Exp AND Exp 			{}
	| {toGramTree("Exp");}	Exp OR Exp 				{}
	| {toGramTree("Exp");}	Exp RELOP Exp 			{}
	| {toGramTree("Exp");}	Exp PLUS Exp 			{}
	| {toGramTree("Exp");}	Exp MINUS Exp 			{}
	| {toGramTree("Exp");}Exp STAR Exp 				{}
	| {toGramTree("Exp");}Exp DIV Exp 				{}
	| {toGramTree("Exp");}LP Exp RP 				{}
	| {toGramTree("Exp");}MINUS Exp 				{}
	| {toGramTree("Exp");}NOT Exp 					{}
	| {toGramTree("Exp");}ID LP Args RP 			{}
	| {toGramTree("Exp");}ID LP RP 					{}
	| {toGramTree("Exp");}Exp LB Exp RB 			{}
	| {toGramTree("Exp");}Exp LB Exp error RB 		{err=1; printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	| {toGramTree("Exp");}Exp DOT ID 				{}
	| {toGramTree("Exp");}ID 						{}
	| {toGramTree("Exp");}INT 						{$$.type = INT; $$.value.vali = $2;}
	| {toGramTree("Exp");} FLOAT 					{$$.type = FLOAT; $$.value.valf = $2;}
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
	if(!err){
		printf("gramTree:\n%s",gramTree);
	}
	
	return 0;
}

void yyerror(char*s){
	char type = 'A';
	printf("Error type %c at Line %d: %s\n",type, yylineno, s);
}
void toGramTree(char *name){
	char tmp[100];
	sprintf(tmp, "%s(%d)\n",name,yylineno);strcat(gramTree, tmp);
}
void tmpcode(){
	/* $$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali + $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)+(($3.type==INT)?$3.value.vali:$3.value.valf);
								*/
}
