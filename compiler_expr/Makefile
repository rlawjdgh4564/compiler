all:
	flex expr.l
	bison -d expr.y
	gcc lex.yy.c expr.tab.c CFG.c -o calc -lfl

clean:
	rm -rf lex.yy.c expr.tab.c expr.tab.h calc sample.out
