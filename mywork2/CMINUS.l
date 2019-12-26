%option noyywrap nodefault yylineno

%{
#include"CMINUS.h"
#include"CMINUS.tab.h"
#include"tree.h"

int base8ConverTo10(int);
int base16ConverTo10(char *);
float readFloat(char *);
int vali;
float valf;
//extern int error;


%}

%%
 /*忽略空白符*/
[ \t]			{}


 /* 对整数的支持(包括8进制和16进制)*/
0				{vali = 0; 				yylval.val = createLeaf(INT, yytext); return INT;}
[1-9][0-9]*		{vali = atoi(yytext);	yylval.val = createLeaf(INT, yytext);	return INT; }
0[1-9][0-9]*	{vali = base8ConverTo10(atoi(yytext)); yylval.val = createLeaf(INT, yytext); return INT;}
0[xX][0-9a-fA-F]*	{vali = base16ConverTo10(yytext); yylval.val = createLeaf(INT, yytext);return INT;}
 /* 浮点数的支持*/
[0-9]+\.[0-9]+						{valf = readFloat(yytext); 			yylval.val = createLeaf(FLOAT, yytext); return FLOAT;}
[0-9]+\.[0-9]*[eE][+-]?[0-9]+	|
\.[0-9]+[eE][+-]?[0-9]+				{valf = readFloat(yytext); 	yylval.val = createLeaf(FLOAT, yytext); return FLOAT;}

 /*关键字*/
"int"				{yylval.val = createLeaf(TYPE, yytext); 	return TYPE;}
"float"				{yylval.val = createLeaf(TYPE, yytext);		return TYPE;}
"struct"			{return STRUCT;}
"return"			{return RETURN;}
"if"				{return IF;}
"else"				{return ELSE;}
"while"				{return WHILE;}

 /*ID*/
[a-zA-Z_][a-zA-Z_0-9]*				{yylval.val = createLeaf(ID, yytext);	return ID;}

 /*标点符号*/
";"				{yylval.val = createLeaf(SEMI, ""); return SEMI;}
","				{yylval.val = createLeaf(COMMA, "");	return COMMA;}
"."				{yylval.val = createLeaf(DOT, "");	return DOT;}
"("				{yylval.val = createLeaf(LP, "");	return LP;}
")"				{yylval.val = createLeaf(RP, "");	return RP;}
"["				{yylval.val = createLeaf(LB, "");	return LB;}
"]"				{yylval.val = createLeaf(RB, "");	return RB;}
"{"				{yylval.val = createLeaf(LC, "");	return LC;}
"}"				{yylval.val = createLeaf(RC, "");	return RC;}

 /*赋值符号*/
"="				{yylval.val = createLeaf(ASSIGNOP, "");return ASSIGNOP;}

 /*比较运算符*/
[><]|">="|"<="|"=="	{yylval.val = createLeaf(RELOP, yytext); return RELOP;}

 /*算术运算符*/
"+"				{yylval.val = createLeaf(PLUS, ""); return PLUS; }
"-"				{yylval.val = createLeaf(MINUS, ""); return MINUS; }
"*"				{yylval.val = createLeaf(STAR, ""); return STAR; }
"/"				{yylval.val = createLeaf(DIV, ""); return DIV; }

 /*逻辑运算符*/
"&&"			{yylval.val = createLeaf(AND, ""); return AND;}
"||"			{yylval.val = createLeaf(OR, ""); return OR;}
"!"				{yylval.val = createLeaf(NOT, "");return NOT;}

\n				{}

.				{printf("Error type A at Line %d:Mysterious character %c\n", yylineno, yytext[0]); return 1;}
%%

/*
int main(int argc, char** argv){
	FILE*f;
	if(argc > 1){
		if(!(f=fopen(argv[1],"r"))){
			perror(argv[1]);
			return 1;
		}
		yyrestart(f);
	}
	
	int tok;
	while(tok = yylex()){
		switch(tok){
			case INT: 	{printf("%d:%d\n", tok, yylval.vali); break;}
			case FLOAT: 	{printf("%d:%f\n", tok, yylval.valf); break;}
			default:	{printf("%d\n",tok);}
		}
		printf("%d\n",tok);
	}
	return 0;
}
*/

int char2int(char c){
	if(c>='0' && c <='9'){
		return c-'0';
	}else if(c>='a' && c <='f'){
		return c-'a' + 10;
	}else if(c>='A' && c <='F'){
		return c-'A' +10;
	}
		
}

float readFloat(char *s){
	int len = strlen(s);
	float result=0, digit=0;
	int i=0;		// 小数位长度
	while(i<len&&s[i]!='e'&&s[i]!='E'){
		if(s[i]=='.'){
			i ++;
			digit = 10;
			continue;
		}
		if(digit==0){
			result = result*10+s[i]-'0';
		}else{
			result += (s[i]-'0')/digit;
			digit *= 10;
		}
		
		i++;
		//printf("step-%d:%f\n",i,result);
	}
	if(i<=len-1){
		i++; // 跳过e/E
		
		float flag=10;	
		if(s[i]=='-'){
			flag = 0.1;	i++;
		}else if(s[i]=='+'){
			i++;
		}
		int power = atoi(&s[i]);
		result *= pow(flag, power);
		//printf("power: %d", power);
		//printf("step-%d:%f\n",i,result);
	}
	//printf("result: %f\n", result);
	return result;
}
int base16ConverTo10(char *s){
	int len = strlen(s), result=0;
	for(int i=2;i<len;i++){
		result = result * 16 + char2int(s[i]);
	}
	return result;
}

int base8ConverTo10(int x){
	int result=0, times=1, tmp;
	while(x!=0){
		tmp = x%10;
		result += tmp *times;
		
		times *= 8;
		x/=10;
	}
	return result;
}