#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 
#include <malloc.h> 
/* 符号表的数据类型，每个符号元素表将保存函数名和变量名和 对应的类型及其数值或函数指针，符号表以链表方式实现 */ 
struct symrec { 
	char *name; /* 符号名 */ 
	int type; /* 符号类型 */ 
	union { 
		double var; /* 变量的数值 */ 
		double (*fnctptr)(); /* 函数指针 */ 
	} value; 
	struct symrec *next; /* 指向下一个符号单元 */ 
}; 
typedef struct symrec SYMREC; /* 符号表的应用定义*/ 
//extern SYMREC *sym_table; 



