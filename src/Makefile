all :
	flex lexer.l
	bison -t -v -d parser.y 
	g++ -o parser lex.yy.c parser.tab.c AST.cpp main.cpp

	