#include "calc.h" 
#include "mcalc.tab.h" /* bison为mcalc.tab.h */ 
extern int yyparse(); 
struct init { 
	char *fname; 
	double (*fnct)(); 
}; 
struct init arith_fncts[] = { 
	"sin", sin, "cos", cos, "atan", atan, "ln", log,
	"exp", exp, "sqrt", sqrt, 0, 0 }; 
/* 定义符号表表头指针，其初值为空指针 */ 
SYMREC *sym_table = (SYMREC *)0; 
SYMREC * putsym (char *sym_name, int sym_type) { 
	SYMREC *ptr; ptr = (SYMREC *) malloc (sizeof (SYMREC)); 
	ptr->name = (char *) malloc (strlen (sym_name) + 1); 
	strcpy (ptr->name,sym_name); 
	ptr->type = sym_type; 
	ptr->value.var = 0; /* set value to 0 even if fctn. */ 
	ptr->next = (SYMREC *)sym_table; 
	sym_table = ptr; 
	return ptr; 
}

SYMREC * getsym (char *sym_name) { 
	SYMREC *ptr; 
	for (ptr = sym_table; ptr != (SYMREC *) 0; ptr = (SYMREC *)ptr->next )
		if (strcmp (ptr->name,sym_name) == 0) 
			return ptr; 
	return 0; 
} 
void init_table () /* 将数学函数预置于符号表中 */ 
{ 	int i; 
	SYMREC *ptr; 
	for (i = 0; arith_fncts[i].fname != 0; i++) { 
		ptr = putsym (arith_fncts[i].fname, FNCT); 
		ptr->value.fnctptr = arith_fncts[i].fnct; 
	} 
}
int main() { 
	extern int yydebug;
	yydebug = 1;

	init_table(); 
	yyparse(); 
	
	return 0;
}

