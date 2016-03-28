/1d1/amba/tools/shell_files/add_@.pl < $1 > jnk.t
/1d1/amba/tools/shell_files/join_wrds.pl < jnk.t > jnk.t1
/1d1/amba/DEVA*/new_cnvrt.out r < jnk.t1 > jnk.rom
#sed '1,$s/lY/lV/g
#     1,$s/rY/r/g
#     1,$s/Z//g
#     1,$s/#/$ /g
#     1,$s/\"/ " /g
#     1,$s/,/ ,/g
#     1,$s/\. / . /g
#     1,$s/\.\n/ .\n/g
#     1,$s/?/ ?/g
#     1,$s/!/ !/g
#     1,$s/;/ ;/g
#     1,$s/:/ :/g
#     1,$s/)/ )/g
#     1,$s/(/ ( /g' < jnk.rom > $2
/1d1/amba/tools/shell_files/sep_punct.pl < jnk.rom > $2
#rm jnk.t jnk.rom jnk.t1
