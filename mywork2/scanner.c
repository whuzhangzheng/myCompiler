#include "calc.h" 
#include "mcalc.tab.h" /* DOS的byacc输出的头文件，bison为mcalc.tab.h */ 
extern YYSTYPE yylval; 
extern char lexeme[]; 
int yylex () { 
	int c; /* 跳过白字符 */ 
	while ((c = getchar ()) == ' ' || c == '\t')
		;
	if (c == EOF) 
		return 0; 
	/* 读取数值常量 */ 
	if (c == '.' || isdigit (c)) {
		ungetc (c, stdin); 
		scanf ("%lf", &yylval.val); 
		sprintf(lexeme, "%lf", yylval.val); /* 记录词形 */ 
		return NUM; 
	} if (isalpha (c)) {/* 读取标识符 */ 
		SYMREC *s; 
		static char *symbuf = 0; 
		static int length = 0; 
		int i; /* 动态申请一个长度为41的字符数组保存词形 */
		if (length == 0) 
			length = 40, symbuf = (char *)malloc(length + 1); 
		i = 0; 
		do { /* 如果词形的长度超过40，重新分配双倍的内存 */ 
			if (i == length) {
				length *= 2; 
				symbuf = (char *)realloc(symbuf, length + 1); 
			} 
			symbuf[i++] = c; /* 保存当前字符到数组symbuf中 */ 
			c = getchar (); /* 读取下一个字符 */ 
		} while (c != EOF && isalnum (c)); 
		ungetc (c, stdin); /* 回退最后一个字符到输入 */ 
		symbuf[i] = '\0'; /* 查看符号表，如果不在其中表示新定义变量 */ 
		s = getsym (symbuf); 
		if (s == 0) s = putsym (symbuf, VAR); 
		yylval.tptr = s; 
		sprintf(lexeme, s->name,79); /* 返回词形 */ 
		lexeme[79] = 0; 
		return s->type; 
	} 
	/* 对其他的字符返回其ASCII码 */ 
	lexeme[0] = c; 
	lexeme[1] = 0; 
	return c; 
}

