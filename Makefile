FLEX = flex
BISON = bison

exe: lex.l yacc.y
	$(BISON) --output="yacc.tab.cpp" --defines="yacc.tab.h" yacc.y
	$(FLEX) --outfile="lex.yy.cpp" lex.l
	g++ lex.yy.cpp yacc.tab.cpp symbol.cpp gramtree.cpp
	
clean:
	rm -rf lex.yy.cpp yacc.tab.cpp a.out yacc.tab.h output.asm

test:
	./a.out test.c
	
asm:
	nasm -f elf output.asm -o output.o
	gcc -m32 output.o -o output
	
result:
	./output