flex $1.lex
cc -g -o $1.out lex.yy.c -lfl 
#rm lex.yy.c
