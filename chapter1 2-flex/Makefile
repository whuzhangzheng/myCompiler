.PHONY:testMake

TIME = $(shell date)
testMake:
#	@echo ${TIME}
	$${HOME}
	
%.fbcpp: %.l %.y
	@bison -d $*.y
	@flex $*.l
	g++ $*.tab.c lex.yy.c -lfl -Llibs/ -o $@
#	g++ fb1-5.tab.c lex.yy.c ./libfl.a -o $@
#g++ fb1-5.tab.c lex.yy.c -o e1_5 -lfl -B ./libs/

%.fb: %.l %.y
	@bison -d $*.y
	@flex $*.l
	gcc $*.tab.c lex.yy.c -lfl -Llibs/ -o $*
%.flexpp: %.l
	flex $<
	g++ lex.yy.c -lfl -B ./libs/
	
%.flex:%.l 
	flex $<
	gcc lex.yy.c -o $*.exe -lfl -Llibs/

	