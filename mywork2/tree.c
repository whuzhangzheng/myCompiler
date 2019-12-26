#include "CMINUS.tab.h"
#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Node* createLeaf(int tag, char *text){
	struct Node *nd=(struct Node*)malloc(sizeof(struct Node));
	nd->ncld=0;
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

struct Node *createNode(int tag, int ncld, struct Node *a[])
{
	int i;
	struct Node *nd=(struct Node*)malloc(sizeof(struct Node));
	nd->ncld=ncld;
	nd->tag=tag;
	nd->value=NULL;
	for(i=0; i<nd->ncld; i++)
		(nd->cld)[i]=a[i];
	return nd;
}


struct Node *createEmpty()
{
	struct Node *nd=(struct Node*)malloc(sizeof(struct Node));
	nd->ncld=0;
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
		
		if(nd->value==NULL)
			printf("%s\n", getTag(nd->tag));
		else 
			printf("%s:%s\n", getTag(nd->tag), nd->value);
		
		for (i=0; i<nd->ncld; i++) {  
			treePrintLevel((nd->cld)[i], lvl+1);
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
		case COMPST : return "COMPST";
		case STMTLIST : return "StmtList";
		case STMT : return "Stmt";
		case DEFLIST : return "DefList";
		case DEF : return "Def";
		case DECLIST : return "DecList";
		case DEC : return "Dec";
		case EXP : return "Exp";
		case ARGS : return "Args";
		case TYPE: return "Type";
		default: return "";
	}
}