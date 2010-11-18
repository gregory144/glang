all:
	bison -d parser.y
	flex lexer.l
	gcc -g -o glang *.h *.c -ly -lfl

clean:
	rm lex.yy.c parser.tab.* glang
