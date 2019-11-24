#include "calc.h" 
#include "mcalc.tab.h" /* DOS��byacc�����ͷ�ļ���bisonΪmcalc.tab.h */ 
extern YYSTYPE yylval; 
extern char lexeme[]; 
int yylex () { 
	int c; /* �������ַ� */ 
	while ((c = getchar ()) == ' ' || c == '\t')
		;
	if (c == EOF) 
		return 0; 
	/* ��ȡ��ֵ���� */ 
	if (c == '.' || isdigit (c)) {
		ungetc (c, stdin); 
		scanf ("%lf", &yylval.val); 
		sprintf(lexeme, "%lf", yylval.val); /* ��¼���� */ 
		return NUM; 
	} if (isalpha (c)) {/* ��ȡ��ʶ�� */ 
		SYMREC *s; 
		static char *symbuf = 0; 
		static int length = 0; 
		int i; /* ��̬����һ������Ϊ41���ַ����鱣����� */
		if (length == 0) 
			length = 40, symbuf = (char *)malloc(length + 1); 
		i = 0; 
		do { /* ������εĳ��ȳ���40�����·���˫�����ڴ� */ 
			if (i == length) {
				length *= 2; 
				symbuf = (char *)realloc(symbuf, length + 1); 
			} 
			symbuf[i++] = c; /* ���浱ǰ�ַ�������symbuf�� */ 
			c = getchar (); /* ��ȡ��һ���ַ� */ 
		} while (c != EOF && isalnum (c)); 
		ungetc (c, stdin); /* �������һ���ַ������� */ 
		symbuf[i] = '\0'; /* �鿴���ű�����������б�ʾ�¶������ */ 
		s = getsym (symbuf); 
		if (s == 0) s = putsym (symbuf, VAR); 
		yylval.tptr = s; 
		sprintf(lexeme, s->name,79); /* ���ش��� */ 
		lexeme[79] = 0; 
		return s->type; 
	} 
	/* ���������ַ�������ASCII�� */ 
	lexeme[0] = c; 
	lexeme[1] = 0; 
	return c; 
}

