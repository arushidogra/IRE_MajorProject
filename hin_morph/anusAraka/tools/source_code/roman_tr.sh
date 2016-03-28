From vc Sun Oct 18 15:50:07 1992
Return-Path: <vc>
Received: from csesparc1.iitkan.ernet.in by csesun1.iitk.ernet.in (4.0/SMI-4.0)
	id AA27939; Sun, 18 Oct 92 15:50:05 IST
Date: Sun, 18 Oct 92 15:50:05 IST
From: vc (vineet chaitanya)
Message-Id: <9210181020.AA27939@csesun1.iitk.ernet.in>
To: amba
Subject: roman transliteration tool
Status: RO

 # PURPOSE:This converts the standard_dev_rom file to a 
 # 	   readable but less accuurate roman notation .
 # USAGE:   roman_tr.sh <file_name>
 # OUTPUT: <file_name>_roman
 # WARNING:Files named junk.jnktmp , junk.jnktmp1 will be
 # 	   erased in addition to the output file
tr zfFqQRwWxX MnnrrStTdD <$1 > junk.jnktmp
sed -e   's/K/kh/g
	  s/G/gh/g
	  s/C/ch/g
	  s/J/jh/g
	  s/T/th/g
	  s/D/dh/g
	  s/P/ph/g
	  s/B/bh/g
	  s/S/sh/g
	  s/E/ai/g
	  s/O/au/g
	  s/L/lr/g
	  s/Z//g' <junk.jnktmp >junk.jnktmp1
tr MHN mhn <junk.jnktmp1 >$1_roman
rm junk.jnktmp junk.jnktmp1
 Any comments ?

