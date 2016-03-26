CC = gcc
CC_FLAGS = -Wall -Werror -g -DGNU -c
INCLUDE_C_DATA =./data/
OBJECTF = Avy_srch.o avy.o new_build_struct_hin.o chk_uword_dict.o const.o cp_suff_add_struct.o cp_to_struct.o cp_to_struct_chk_pdgm.o dict_lookup.o feature_value.o get_paradigm.o get_pdgm_info.o get_suff.o main.o morph_hindi.o my_fatal.o match_dict.o order_ssf.o print.o print_ssf_hori.o print_default_ans.o read_file.o snt_mark.o suff_build_struct.o suff_info.o suff_tab_lookup.o verify_root.o fgetword.o my_blk_bsrch.o my_bsrch.o get_spell_variation.o lex_port.o print_spell_variation.o morph_logger.o
morph_hin.exe : ${OBJECTF}
	${CC} -o morph_hin.exe ${OBJECTF} -lgdbm `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0`
fgetword.o : fgetword.c morph_logger.h
	${CC} ${CC_FLAGS} fgetword.c
my_blk_bsrch.o : my_blk_bsrch.c
	${CC} ${CC_FLAGS} my_blk_bsrch.c
my_bsrch.o : my_bsrch.c
	${CC} ${CC_FLAGS} my_bsrch.c
Avy_srch.o : Avy_srch.c
	${CC} ${CC_FLAGS} Avy_srch.c
avy.o : data_files ${INCLUDE_C_DATA}avy.c defn.h ${INCLUDE_C_DATA}const.h
	${CC} ${CC_FLAGS} ${INCLUDE_C_DATA}avy.c
new_build_struct_hin.o : new_build_struct_hin.c struct.h
	${CC} ${CC_FLAGS} new_build_struct_hin.c
chk_uword_dict.o : chk_uword_dict.c defn.h struct1.h
	${CC} ${CC_FLAGS} chk_uword_dict.c
const.o : data_files ${INCLUDE_C_DATA}const.c
	${CC} ${CC_FLAGS} ${INCLUDE_C_DATA}const.c
cp_suff_add_struct.o : cp_suff_add_struct.c struct.h struct1.h
	${CC} ${CC_FLAGS} cp_suff_add_struct.c
cp_to_struct.o : cp_to_struct.c struct.h
	${CC} ${CC_FLAGS} cp_to_struct.c
cp_to_struct_chk_pdgm.o : cp_to_struct_chk_pdgm.c struct.h
	${CC} ${CC_FLAGS} cp_to_struct_chk_pdgm.c
dict_lookup.o : dict_lookup.c defn.h
	${CC} ${CC_FLAGS} dict_lookup.c
feature_value.o : data_files ${INCLUDE_C_DATA}feature_value.c defn.h ${INCLUDE_C_DATA}const.h
	${CC} ${CC_FLAGS} ${INCLUDE_C_DATA}feature_value.c
get_paradigm.o : get_paradigm.c defn.h
	${CC} ${CC_FLAGS} get_paradigm.c
get_pdgm_info.o : get_pdgm_info.c defn.h
	${CC} ${CC_FLAGS} get_pdgm_info.c
get_suff.o : get_suff.c defn.h
	${CC} ${CC_FLAGS} get_suff.c
lex_port.o : lex_port.c const.h struct.h
	${CC} ${CC_FLAGS} lex_port.c
main.o : main.c struct.h struct1.h defn.h glbl.h morph_logger.h
	${CC} `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` ${CC_FLAGS} main.c
morph_logger.o: morph_logger.c
	${CC} ${CC_FLAGS} morph_logger.c
my_fatal.o : my_fatal.c
	${CC} ${CC_FLAGS} my_fatal.c
match_dict.o : match_dict.c defn.h struct.h struct1.h
	${CC} ${CC_FLAGS} match_dict.c
morph_hindi.o : morph_hindi.c struct.h struct1.h
	${CC} ${CC_FLAGS} morph_hindi.c
order_ssf.o : order_ssf.c
	${CC} ${CC_FLAGS} order_ssf.c
print.o : print.c struct.h
	${CC} ${CC_FLAGS} print.c
print_ssf_hori.o : print_ssf_hori.c struct.h
	${CC} ${CC_FLAGS} print_ssf_hori.c
print_default_ans.o : print_default_ans.c defn.h morph_logger.h
	${CC} ${CC_FLAGS} print_default_ans.c
read_file.o : read_file.c defn.h
	${CC} ${CC_FLAGS} read_file.c
snt_mark.o : snt_mark.c defn.h
	${CC} ${CC_FLAGS} snt_mark.c
suff_build_struct.o : suff_build_struct.c defn.h struct.h
	${CC} ${CC_FLAGS} suff_build_struct.c
suff_tab_lookup.o : suff_tab_lookup.c defn.h struct.h
	${CC} ${CC_FLAGS} suff_tab_lookup.c
suff_info.o : data_files ${INCLUDE_C_DATA}suff_info.c struct.h ${INCLUDE_C_DATA}const.h
	${CC} ${CC_FLAGS} ${INCLUDE_C_DATA}suff_info.c
verify_root.o : verify_root.c struct.h struct1.h defn.h
	${CC} ${CC_FLAGS} verify_root.c
get_spell_variation.o : get_spell_variation.c
	${CC} ${CC_FLAGS} get_spell_variation.c
print_spell_variation.o : print_spell_variation.c struct1.h
	${CC} ${CC_FLAGS} print_spell_variation.c
data_files:
	make -C data/shell
clean:
	rm -f ./*.o
	rm -f ./morph_hin.exe
	make -C data/shell clean
