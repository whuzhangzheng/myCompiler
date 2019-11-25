%option noyywrap nodefault yylineno

%{
#include"CMINUS.h"
#include"CMINUS.tab.h"
int base8ConverTo10(int);
int base16ConverTo10(char *);
float readFloat(char *);


%}

%%
 /*忽略空白符*/
[ \t]			{}


 /* 对整数的支持(包括8进制和16进制)*/
0				{yylval.vali = 0; return INT;}
[1-9][0-9]*		{yylval.vali = atoi(yytext); return INT; }
0[1-9][0-9]*	{yylval.vali = base8ConverTo10(atoi(yytext)); return INT;}
0[xX][0-9a-fA-F]*	{yylval.vali = base16ConverTo10(yytext); return INT;}
 /* 浮点数的支持*/
[0-9]+\.[0-9]+						{yylval.valf = readFloat(yytext); return FLOAT;}
[0-9]+\.[0-9]*[eE][+-]?[0-9]+	|
\.[0-9]+[eE][+-]?[0-9]+				{yylval.valf = readFloat(yytext); return FLOAT;}

 /*关键字*/
"int"|"float"		{return TYPE;}
"struct"			{return STRUCT;}
"return"			{return RETURN;}
"if"				{return IF;}
"else"				{return ELSE;}
"while"				{return WHILE;}

 /*ID*/
[a-zA-Z_][a-zA-Z_0-9]				{return ID;}

 /*标点符号*/
";"				{return SEMI;}
","				{return COMMA;}
"."				{return DOT;}
"("				{return LP;}
")"				{return RP;}
"["				{return LB;}
"]"				{return RB;}
"{"				{return LC;}
"}"				{return RC;}

 /*赋值符号*/
"="				{return ASSIGNOP;}

 /*比较运算符*/
[><]|">="|"<="|"=="	{return RELOP;}

 /*算术运算符*/
"+"				{ return PLUS; }
"-"				{ return MINUS; }
"*"				{ return STAR; }
"/"				{ return DIV; }

 /*逻辑运算符*/
"&&"			{return AND;}
"||"			{return OR;}
"!"				{return NOT;}

\n				{}
%%


int main(){
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