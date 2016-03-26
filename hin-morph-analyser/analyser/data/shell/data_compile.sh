export LC_ALL=C
sh info.sh
sh lext.sh
sh main2.sh

rm -f ../suff
rm -f ../uword.dbm
sh mk_dbm_suffix
sh mk_dbm_suff
sh mk_dbm_uword
chmod 644 ../suff  ../uword.dbm
