
%{
#include"CMINUS.h"
#include"tree.h"

void yyerror(char *);
int yylex();

extern int yylineno;
struct Node *cldArray[10];
int cldN;
int nTag;

int ifError = 0;
%}

%union{
	struct Node * val;
}

%token <val>INT 					// 258
%token <val>FLOAT					// 259
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

%type <val> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec FunDec VarList  
%type <val> ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%%

Program : ExtDefList 			{nTag=PROGRAM; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray); 
								if(!ifError) treePrint($$);}
ExtDefList :	/*定义列表*/	{$$=NULL;}
	| ExtDef ExtDefList 		{nTag=EXTDEFLIST; cldN=2; cldArray[0]=$1; cldArray[1]=$2;
								$$=createNode(nTag, cldN, cldArray); }
	;	 
ExtDef : Specifier ExtDecList SEMI	{nTag=EXTDEF; cldN=3; cldArray[0]=$1; cldArray[1]=$2; cldArray[2]=$3;
								$$=createNode(nTag, cldN, cldArray); } 
	| Specifier SEMI 			{nTag=EXTDEF; cldN=2; cldArray[0]=$1; cldArray[1]=$2;
								$$=createNode(nTag, cldN, cldArray); }
	| Specifier FunDec CompSt 	{nTag=EXTDEF; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3;
								$$=createNode(nTag, cldN, cldArray); }
	;
ExtDecList : VarDec 			{nTag=EXTDECLIST; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	| VarDec COMMA ExtDecList	{nTag=EXTDECLIST; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3;
								$$=createNode(nTag, cldN, cldArray); }
	;
Specifier : TYPE 				{nTag=SPECIFIER; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	| StructSpecifier 			{nTag=SPECIFIER; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	;
StructSpecifier : STRUCT OptTag LC DefList RC	 {nTag=STRUCTSPECIFIER; cldN=5; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5;
								$$=createNode(nTag, cldN, cldArray); }
	| STRUCT Tag 				{nTag=STRUCTSPECIFIER; cldN=2; cldArray[0]=$1; cldArray[1]=$2;	
								$$=createNode(nTag, cldN, cldArray); }
	;
OptTag :  						{$$=NULL;}
	| ID						{nTag=OPTTAG; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	;
Tag : ID						{nTag=TAG; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	;
VarDec : ID 					{nTag=VARDEC; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	| VarDec LB INT RB			{nTag=VARDEC; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; 
								$$=createNode(nTag, cldN, cldArray); }
	| VarDec LB INT error RB	{nTag=VARDEC; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3;  cldArray[3]=$5;
									$$=createNode(nTag, cldN, cldArray); 
									printf("Error Type B at Line %d: Missing \"]\"\n", yylineno);}
	;
FunDec : ID LP VarList RP 		{nTag=FUNDEC; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; 
								$$=createNode(nTag, cldN, cldArray); }
	| ID LP RP 					{nTag=FUNDEC; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	;
VarList : ParamDec COMMA VarList {nTag=VARLIST; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| ParamDec 					{nTag=VARLIST; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	;
ParamDec : Specifier VarDec		{nTag=PARAMDEC; cldN=2; cldArray[0]=$1; cldArray[1]=$2;	
								$$=createNode(nTag, cldN, cldArray); }
	;
CompSt : LC DefList StmtList RC  {nTag=COMPST; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; 
								$$=createNode(nTag, cldN, cldArray); }
	;
StmtList : 						{$$=NULL;}
	| Stmt StmtList 			{nTag=STMTLIST; cldN=2; cldArray[0]=$1; cldArray[1]=$2;	
								$$=createNode(nTag, cldN, cldArray); }
	;
Stmt : Exp SEMI 				{nTag=STMT; cldN=2; cldArray[0]=$1; cldArray[1]=$2;	
								$$=createNode(nTag, cldN, cldArray); }
	| Exp error SEMI 			{nTag=STMT; cldN=2; cldArray[0]=$1; cldArray[1]=$3;	
								$$=createNode(nTag, cldN, cldArray);
								printf("Error Type B at Line %d: Missing \";\"\n", yylineno); ifError=1;}
	| CompSt 					{nTag=STMT; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	| RETURN Exp SEMI 			{nTag=STMT; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| IF LP Exp RP Stmt 		{nTag=STMT; cldN=5; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5;
								$$=createNode(nTag, cldN, cldArray); }
	| IF LP Exp RP Stmt ELSE Stmt	{nTag=STMT; cldN=7; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5;
									cldArray[5]=$6;cldArray[6]=$7;
								$$=createNode(nTag, cldN, cldArray); } 
	| WHILE LP Exp RP Stmt 		{nTag=STMT; cldN=5; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; cldArray[4]=$5;
								$$=createNode(nTag, cldN, cldArray); }
	;
DefList : 						{$$=NULL;}
	|Def DefList 				{nTag=DEFLIST; cldN=2; cldArray[0]=$1; cldArray[1]=$2; $$=createNode(nTag, cldN, cldArray);	}
	;
Def : Specifier DecList SEMI 	{nTag=DEF; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	;
DecList : Dec 					{nTag=DECLIST; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	| Dec COMMA DecList 		{nTag=DECLIST; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	;
Dec : VarDec 					{nTag=DEC; cldN=1; cldArray[0]=$1; $$=createNode(nTag, cldN, cldArray);}
	| VarDec ASSIGNOP Exp 		{nTag=DEC; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| VarDec ASSIGNOP error Exp 		{nTag=DEC; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$4; 
								$$=createNode(nTag, cldN, cldArray); }
	;
	
// 表达式
Exp : Exp ASSIGNOP Exp 			{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp AND Exp 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp OR Exp 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp RELOP Exp 			{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp PLUS Exp 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp MINUS Exp 			{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp STAR Exp 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp DIV Exp 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| LP Exp RP 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| MINUS Exp 				{nTag=EXP; cldN=2; cldArray[0]=$1; cldArray[1]=$2;	
								$$=createNode(nTag, cldN, cldArray); }
	| NOT Exp 					{nTag=EXP; cldN=2; cldArray[0]=$1; cldArray[1]=$2;	
								$$=createNode(nTag, cldN, cldArray); }
	| ID LP Args RP 			{nTag=EXP; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; cldArray[3]=$4; 
								$$=createNode(nTag, cldN, cldArray); }
	| ID LP RP 					{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp LB Exp RB 			{nTag=EXP; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3;  cldArray[3]=$4;  
								$$=createNode(nTag, cldN, cldArray); }
	| Exp LB Exp error RB 		{nTag=EXP; cldN=4; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3;  cldArray[3]=$5; 
								$$=createNode(nTag, cldN, cldArray); 
								printf("Error Type B at Line %d: Missing \"]\"\n", yylineno); ifError=1; }
	| Exp DOT ID 				{nTag=EXP; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| ID 						{nTag=EXP; cldN=1; cldArray[0]=$1; 
								$$=createNode(nTag, cldN, cldArray); }
	| INT 						{nTag=EXP; cldN=1; cldArray[0]=$1; 
								$$=createNode(nTag, cldN, cldArray); }
	| FLOAT 					{nTag=EXP; cldN=1; cldArray[0]=$1; 
								$$=createNode(nTag, cldN, cldArray); }
	;
Args : Exp COMMA Args 			{nTag=ARGS; cldN=3; cldArray[0]=$1; cldArray[1]=$2;	cldArray[2]=$3; 
								$$=createNode(nTag, cldN, cldArray); }
	| Exp						{nTag=ARGS; cldN=1; cldArray[0]=$1; 
								$$=createNode(nTag, cldN, cldArray); }
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