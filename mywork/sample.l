%{
  #include<iostream>
  #include<string>
  extern "C" {
    int yywrap();
  } 
  std::string str;
  std::string num;
%}
 
 
%%
[a-zA-Z]+ { str += yytext; return 1; } 
[0-9]+ { num += yytext;  return 1; }
\n   { return 0; }
%%
 
int yywrap() { return 1; }
 
 
int main() {
  while( yylex() );
  std::cout<<"Number: " << num <<std::endl;
  std::cout<<"String: " << str <<std::endl;
  return 0;
}
