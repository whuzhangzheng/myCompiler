#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 
#include <malloc.h> 
/* ���ű���������ͣ�ÿ������Ԫ�ر����溯�����ͱ������� ��Ӧ�����ͼ�����ֵ����ָ�룬���ű�������ʽʵ�� */ 
struct symrec { 
	char *name; /* ������ */ 
	int type; /* �������� */ 
	union { 
		double var; /* ��������ֵ */ 
		double (*fnctptr)(); /* ����ָ�� */ 
	} value; 
	struct symrec *next; /* ָ����һ�����ŵ�Ԫ */ 
}; 
typedef struct symrec SYMREC; /* ���ű��Ӧ�ö���*/ 
//extern SYMREC *sym_table; 



