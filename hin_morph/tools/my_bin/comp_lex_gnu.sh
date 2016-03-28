flex $1.lex
cc -g -DGNU -o $1.out lex.yy.c -lfl -lgdbm
#rm lex.yy.c
