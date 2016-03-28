# This generates ln executable file which is used by prn.sh
flex /1d1/mt/tools/source_code/ln.l
cc -o /1d1/mt/tools/lib/ln.out lex.yy.c -lfl
