
#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 
#include <malloc.h> 
/* 符号表的数据类型，每个符号元素表将保存函数名和变量名和 对应的类型及其数值或函数指针，符号表以链表方式实现 */ 
struct symrec { 
	char *name; /* 符号名 */ 
	int type; /* 符号类型 INT:整数(int a;)  FLOATL:浮点数(float a;)   STRUCT   FNCT  */ 
	union { 
		int vali; 		/* 整型变量的语义值 */ 
		float valf;		/* 浮点型变量的语义值 */ 
		/*结构体变量的语义值应该是什么*/
		double (*fnctptr)(); /* 函数指针 */ 
	} value; 
	struct symrec *next; /* 指向下一个符号单元 */ 
}; 
typedef struct symrec SYMREC; /* 符号表的应用定义*/


struct expVal{
	int type;		// INT   FLOAT
	union {
		int vali; 		/* 整型变量的语义值 */ 
		float valf;		/* 浮点型变量的语义值 */ 
		/*结构体变量的语义值应该是什么*/
		double (*fnctptr)(); /* 函数指针 */ 
	}value;
};
typedef struct expVal EXPVAL;
//extern SYMREC *sym_table; 

struct Node{
	int level;
};
typedef struct Node NODE;
