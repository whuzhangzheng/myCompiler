
%{
#include"CMINUS.h"

void yyerror(char *);
int yylex();
void toGramTree(int level ,char *name);

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
	NODE node;
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
%token ERRORA

%type <expval> Exp
%type <node> Program ExtDefList 

%%

Program : 	{ toGramTree(0,"Program");  } 	ExtDefList 		{$2.level=1;}	
ExtDefList:	{}
	| 		{toGramTree(1,"ExtDefList"); } 	ExtDef  ExtDefList 		
	;	 
ExtDef:  	Specifier  ExtDecList  SEMI	{}
	| 		Specifier 	SEMI 				{}
	| 		{toGramTree(2,"ExtDef");} Specifier 	 FunDec  CompSt 	{}
	;
ExtDecList : VarDec {toGramTree(0,"ExtDecList");}		
	| 		VarDec {toGramTree(0,"ExtDecList");}  COMMA ExtDecList	{}
	;
Specifier : {toGramTree(3,"Specifier");}	TYPE	{toGramTree(0,"TYPE");} 				
	| 		{toGramTree(3,"Specifier");}		StructSpecifier 			{}
	;
StructSpecifier : STRUCT OptTag LC DefList RC	{} 
	| STRUCT Tag 				{}
	;
OptTag :  						{}
	| ID						{}
	;
Tag : ID						{}
	;
VarDec : {toGramTree(0,"VarDec");} 	ID 					{}
	| 		VarDec LB INT RB			{toGramTree(0,"VarDec");}
	| {toGramTree(0,"VarDec");}		VarDec LB INT error RB	{toGramTree(0,"VarDec"); err = 1;printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	;
FunDec:  ID LP{toGramTree(0,"FunDec");} VarList RP 		{}
	|	ID LP {toGramTree(0,"FunDec");} RP 					{toGramTree(0,"ID\nLP\nRP");}
	;
VarList : ParamDec COMMA VarList {}
	| ParamDec 					{}
	;
ParamDec : Specifier VarDec		{}
	;
CompSt : {toGramTree(0,"CompSt");}		LC DefList StmtList RC {}
	;
StmtList : 						{/* \epsilon */}
	|	{toGramTree(0,"StmtList");} Stmt StmtList 			{}
	;
Stmt :  {toGramTree(0,"Stmt");}Exp  SEMI 				{}
	| 	{toGramTree(0,"Stmt");}Exp		 error SEMI 			{err=1; printf("Error Type B at Line %d: Missing \";\"\n", yylineno);}
	| {toGramTree(0,"Stmt");}		CompSt 					{}
	| {toGramTree(0,"Stmt");}		RETURN Exp SEMI 			{}
	| 	IF LP Exp RP Stmt 		{toGramTree(0,"Stmt");}	
	| 	IF LP Exp RP Stmt ELSE {toGramTree(0,"Stmt");}  Stmt	{} 
	| {toGramTree(0,"Stmt");}		WHILE LP Exp RP Stmt 		{}
	;
DefList : 						{}
	|{toGramTree(0,"DefList");}		Def DefList 				{}
	;
Def : {toGramTree(0,"Def");}			Specifier DecList SEMI 	{}
	;
DecList :  	Dec 					{toGramTree(0,"DecList");}
	| 		Dec COMMA DecList 		{toGramTree(0,"DecList");}
	;
Dec : 	VarDec 					{toGramTree(0,"Dec");}
	| VarDec ASSIGNOP Exp 		{toGramTree(0,"Dec");}	
	| VarDec ASSIGNOP error Exp {toGramTree(0,"Dec"); 	err=1;}
	;
	
// 表达式
Exp :	Exp ASSIGNOP Exp 		{toGramTree(0,"Exp"); /*$$.type = $3.type; */}
	| 	Exp AND Exp 			{toGramTree(0,"Exp");}
	| 	Exp OR Exp 				{toGramTree(0,"Exp");}
	| 	Exp RELOP Exp 			{toGramTree(0,"Exp");}
	| 	Exp PLUS Exp 			{toGramTree(0,"Exp");}
	| 	Exp MINUS Exp 			{toGramTree(0,"Exp");}
	| 	Exp STAR Exp 			{toGramTree(0,"Exp");}
	| 	Exp DIV Exp 			{toGramTree(0,"Exp");}
	| 	LP Exp RP 				{toGramTree(0,"Exp");}
	|	MINUS Exp 				{toGramTree(0,"Exp");}
	| 	NOT Exp 				{toGramTree(0,"Exp");}
	| 	ID LP Args RP 			{toGramTree(0,"Exp");}
	| 	ID LP RP 				{toGramTree(0,"Exp");}
	| 	Exp LB Exp RB 			{toGramTree(0,"Exp");}
	| 	Exp LB Exp error RB 	{toGramTree(0,"Exp"); err=1; printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	| 	Exp DOT ID 				{toGramTree(0,"Exp");}
	| 	ID 						{toGramTree(0,"Exp");}
	| 	INT 					{toGramTree(0,"Exp"); 	$$.type = INT; $$.value.vali = $1;}
	| 	FLOAT 					{toGramTree(0,"Exp");		$$.type = FLOAT; $$.value.valf = $1;}
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

void toGramTree(int level, char *name){
	char tmp[100];
	for(int i=0;i<level;i++){
		strcat(gramTree, " ");
	}
	sprintf(tmp, "%s(%d)\n",name,yylineno);strcat(gramTree, tmp);
}
void tmpcode(){
	/* $$.type = ($1.type==INT && $3.type==INT)?INT:FLOAT; 
								 if		($$.type==INT) {$$.value.vali =  $1.value.vali + $3.value.vali;}
								 else 	$$.value.valf = (($1.type==INT)?$1.value.vali:$1.value.valf)+(($3.type==INT)?$3.value.vali:$3.value.valf);
								*/
}
