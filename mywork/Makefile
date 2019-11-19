fb1-5: fb1-5.l fb1-5.y
	@bison -d fb1-5.y
	@flex fb1-5.l
	g++ fb1-5.tab.c lex.yy.c ./libfl.a -o $@
#g++ fb1-5.tab.c lex.yy.c -o e1_5 -lfl -B ./libs/
fb1-4: fb1-4.l
	flex fb1-4.l
	g++ lex.yy.c -lfl -B ./libs/
	