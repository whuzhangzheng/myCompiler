
#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 
#include <malloc.h> 
/* ���ű���������ͣ�ÿ������Ԫ�ر����溯�����ͱ������� ��Ӧ�����ͼ�����ֵ����ָ�룬���ű�������ʽʵ�� */ 
struct symrec { 
	char *name; /* ������ */ 
	int type; /* �������� INT:����(int a;)  FLOATL:������(float a;)   STRUCT   FNCT  */ 
	union { 
		int vali; 		/* ���ͱ���������ֵ */ 
		float valf;		/* �����ͱ���������ֵ */ 
		/*�ṹ�����������ֵӦ����ʲô*/
		double (*fnctptr)(); /* ����ָ�� */ 
	} value; 
	struct symrec *next; /* ָ����һ�����ŵ�Ԫ */ 
}; 
typedef struct symrec SYMREC; /* ���ű��Ӧ�ö���*/


struct expVal{
	int type;		// INT   FLOAT
	union {
		int vali; 		/* ���ͱ���������ֵ */ 
		float valf;		/* �����ͱ���������ֵ */ 
		/*�ṹ�����������ֵӦ����ʲô*/
		double (*fnctptr)(); /* ����ָ�� */ 
	}value;
};
typedef struct expVal EXPVAL;
//extern SYMREC *sym_table; 

struct Node{
	int level;
};
typedef struct Node NODE;
