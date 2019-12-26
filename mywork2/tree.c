#include "CMINUS.tab.h"
#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern int yylineno;
struct Node* createLeaf(int tag, char *text){
	struct Node *nd=(struct Node*)malloc(sizeof(struct Node));
	nd->nchilds=0;
	nd->tag=tag;
	if(tag==ID || tag==TYPE)
	{
		nd->value=(char*)malloc(sizeof(char)*strlen(text));
		strcpy(nd->value,text);
	}
	else
		nd->value=NULL;
	return nd;
}

struct Node *createNode(int tag, int nchilds, struct Node *a[])
{
	int i;
	struct Node *nd=(struct Node*)malloc(sizeof(struct Node));
	nd->nchilds=nchilds;
	nd->tag=tag;
	nd->value=NULL;
	for(i=0; i<nd->nchilds; i++)
		(nd->childs)[i]=a[i];
	nd->lineno = yylineno;
	return nd;
}


struct Node *createEmpty()
{
	struct Node *nd=(struct Node*)malloc(sizeof(struct Node));
	nd->nchilds=0;
	nd->tag=EPS;
	nd->value=NULL;
 
	return nd;
}
void treePrintLevel(struct Node *nd, int lvl)
{
	int i;
	if(nd!=NULL)
	{
		for(i=0; i<2*lvl; i++)
			printf(" ");
		if(nd->nchilds !=0)			// 非叶子节点
			printf("%s(%d)\n", getTag(nd->tag), nd->lineno);
		else if(nd->value==NULL )	// 叶子节点，且没有节点值
			printf("%s\n", getTag(nd->tag));
		else 						// 叶子节点，有节点值
			printf("%s:%s\n", getTag(nd->tag), nd->value);
		
		for (i=0; i<nd->nchilds; i++) {  
			treePrintLevel((nd->childs)[i], lvl+1);
		}
	}
}
 
void treePrint(struct Node *nd)
{
	treePrintLevel(nd, 0);
}

char * getTag(int tag){
	switch(tag){
		case PROGRAM: return "Program";
		case EXTDEFLIST: return "ExtDefList";
		case EXTDEF : return "ExtDef";
		case SPECIFIER : return "Specifier";
		case EXTDECLIST : return "ExtDecList";
		case STRUCTSPECIFIER : return "StructSpecifier";
		case OPTTAG :	return "OptTag";
		case TAG: return "Tag";
		case VARDEC : return "VarDec";
		case FUNDEC : return "FunDec";
		case VARLIST : return "VarList";
		case PARAMDEC : return "ParamDec";
		case COMPST : return "CompSt";
		case STMTLIST : return "StmtList";
		case STMT : return "Stmt";
		case DEFLIST : return "DefList";
		case DEF : return "Def";
		case DECLIST : return "DecList";
		case DEC : return "Dec";
		case EXP : return "Exp";
		case ARGS : return "Args";
		case INT : return "INT"	;				// 258
        case FLOAT	: return "FLOAT";				// 259
        case ID		: return "ID";			// 260
        case SEMI:	return "SEMI";
		case COMMA : return "COMMA"	;		// 261 262	
        case ASSIGNOP: return "ASSIGNOP";
        case RELOP	: return "RELOP";			// 我觉得这个得展开，但暂时忽略	
        case PLUS :		return "PLUS";
		case MINUS:		return "MINUS";
		case STAR :		return "STAR";
		case DIV  :		return "DIV";
        case AND  :		return "AND";
		case OR   :		return "OR";
		case NOT  :		return "NOT";
        case DOT  :		return "DOT";
        case TYPE :		return "TYPE";
        case LP   :		return "LP";
		case RP	  :		return "RP";
        case LB   :		return "LB";
		case RB   :		return "RB";
        case LC   :		return "LC";
		case RC   :		return "RC";
        case STRUCT	:	return "STRUCT";
        case RETURN	:	return "RETURN";
        case IF 	:	return "IF";
		case ELSE	:	return "ELSE";
        case WHILE	:	return "WHILE";
        case FNCT	:	return "FNCT";
		default: return "";
	}
}