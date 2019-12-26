%.flex:%.l 
	flex $<
	gcc lex.yy.c -o $*.exe -lfl -Llibs/

%.bison: %.y
	bison $< -d
	gcc -o $* $*.tab.c 
%.fb: %.l %.y
	@bison -d $*.y
	@flex $*.l
	gcc $*.tab.c lex.yy.c -lfl -Llibs/ -o $*
CMINUS.fb: CMINUS.l CMINUS.y tree.h tree.c
	@bison -d CMINUS.y
	@flex CMINUS.l
	gcc CMINUS.tab.c lex.yy.c tree.c -lfl -Llibs/ -o CMINUS
mcalc: calc.h main.c mcalc.y scanner.c
	bison mcalc.y -d -t
	gcc mcalc.tab.c main.c scanner.c -lfl -Llibs/ -o mcalc