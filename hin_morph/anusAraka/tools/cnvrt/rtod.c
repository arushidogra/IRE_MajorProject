
/* this program converts the text in devanagri to roman 
 & vice versa.
 rtod
 by default every character in roman is halant.
 lY & rY are followed by Y , hqsva-mAwrA-o & hqsva-mAwrA-e are followed by V.
 nukwA is denoted by Z.
 */
#include <stdio.h>
#include <string.h>

#define halanwa 'w'
#define nukwA 'x'
#define blank ' '
#define lY_code 101
#define rY_code 99
#define a_code 67
#define mawra_begin 107
#define mawra_end 119
#define chandra_bindu 65
#define anusvAra 66
#define F_code 75
#define Q_code 112
#define oV_code 116
#define eV_code 113
#define f_code 71
#define visarg_code 66
#define avagraha_code 121


#define SP_CHAR 1 /* ascii<65 && >122 or between 91-96*/
#define CONSONENT 2
#define mAwrA 3
#define a_char 4
#define NUKWA 5
#define HALANWA 6
#define SP_MAWRA 7 /* visarga & chandra_bindu */
#define a_mawra 8 /* mawra starting with a */


char DELIMITER;

/*
char i_to_a[] = "zMakKgGcCjJtTdDNwWxXnpPbBm______yr_lYvSRshAiIuUqYeEYoO_H ";
*/
char i_to_a[] = "zMakKgGcCjJtTdDNwWxXnpPbBm______yr_lYvSRshAiIuUqYeEYoO_HZ";
unsigned char a_to_i[] = "kYIOsKGBmKE_BPvWphgMoeRTey______CXHNrGFjlJDdZUuVpbiLnfQSaA";


int mawra(ch)
unsigned  char ch;
{
	if ((ch == 'A')||(ch=='e')||(ch=='E')||(ch=='i')||(ch=='I')||(ch=='o')||(ch=='O')||(ch=='u')||(ch=='U')||(ch=='q')||(ch=='H')||(ch=='M')||(ch=='z')||(ch=='Q'))return 1; 
	else return 0;
}

int sp_char(ch)
unsigned char ch;
{
if(((ch<65)||(ch>122)||((ch>90)&&(ch<97)))&&(ch!=DELIMITER))
return 1;
else return 0;
}

rtod(in_strng,out_strng)
char *in_strng,*out_strng;
{
int prev_type,curr_type;
char str[3];
get_ch_frm_str(1,in_strng);
put_str_in_str(0,"%s",out_strng);
prev_type=SP_CHAR;
curr_type=SP_CHAR;
while(curr_type!=EOF)
{
curr_type=get_gist_code(str);
switch(curr_type)
{
case a_char :   if(prev_type==SP_CHAR)
                {
                put_ch_in_str(1,"%c",nukwA);
                put_str_in_str(1,"%s",str);
                }
                else if (prev_type==mAwrA)
                      put_str_in_str(1,"%s",str);
                break;
case mAwrA:     if(prev_type==SP_CHAR)
               {
                put_ch_in_str(1,"%c",nukwA);
/*
                if((str[0]!=visarg_code) && ( str[0]!=Q_code)) put_ch_in_str("%c",a_code);
*/
                if(str[0]!=visarg_code) put_ch_in_str(1,"%c",a_code);
               }
                if(((prev_type==a_char)||(prev_type==mAwrA))&&(str[0]!=visarg_code)&&(str[0]!=Q_code)&&(str[0]!=chandra_bindu)&&(str[0]!=avagraha_code))
                put_ch_in_str(1,"%c",a_code);
                put_str_in_str(1,"%s",str);
                break;
case CONSONENT: if(prev_type==SP_CHAR)
                put_ch_in_str(1,"%c",nukwA);
                if(prev_type==CONSONENT)
                put_ch_in_str(1,"%c",halanwa);
                put_str_in_str(1,"%s",str);
                break;
case SP_CHAR: if(prev_type==CONSONENT)
              put_ch_in_str(1,"%c",halanwa);
	      put_str_in_str(1,"%s",str);
              break;
}
prev_type=curr_type;
}
put_str_in_str(2,"%s",out_strng);
return;
}

int get_gist_code(strng)
char strng[3];
{
char f,s,t;
int char_type;
f=get_ch_frm_str(0,"");
if(f==DELIMITER)
{
f=get_ch_frm_str(0,"");
while(f!=DELIMITER)
{
put_ch_in_str(1,"%c",f);
f=get_ch_frm_str(0,"");
}
strng[0]='\0';
return(SP_CHAR);
}
if(f==EOF)
{
char_type=EOF;
return(char_type);
}
/* 	if special character return it. */
if(sp_char(f))
{
strng[0]=f;
strng[1]='\0';
char_type=SP_CHAR;
return(char_type);
}
/* else following cases can be determined without lookahead. */
switch(f)
{
case 'f':
case 'F': strng[0]=a_to_i[f-65];
        strng[1]=nukwA;
        strng[2]='\0';
        char_type=CONSONENT;
        return(char_type);
case 'Q': 
case 'H':strng[0]=a_to_i[f-65];
        strng[1]=nukwA;
        strng[2]='\0';
        char_type=mAwrA;
        return(char_type);
case 'a': strng[0]=a_to_i[f-65];
	  strng[1]='\0';
	  char_type=a_char;
          return(char_type);
case 'Z':strng[0]=a_to_i[f-65];   /* case of   sanskrit avagraha occuring after avagraha */
         strng[1]=nukwA;
         strng[2]='\0';
         strng[1]=nukwA;
         strng[2]='\0';
         char_type=mAwrA;
         return(char_type);
default : break;
}
/* if not a special character & also can not be determined without a look ahead see the next character. 
following_character 	case
	Z		nukwA
	V		ascii code = ascii of the previous character.
	Y		ascii code = ascii of the next character. */

s=get_ch_frm_str(0,"");
switch(s)
{
/* case of non_sanskrit nukwA , assumed that only consonents have nukwA in hindi.*/
case 'Z' : if(!mawra(f) &&(!sp_char(f))) /* case of Consonents in hindi */
            {
             strng[0]=a_to_i[f-65];
             strng[1]=nukwA;
             strng[2]='\0';
             char_type=CONSONENT;
             return(char_type);
            }
        else /* case of sanskrit avagraha  occuring  just after mAwrA */
        {
          strng[0]=a_to_i[f-65];
          strng[1]=a_to_i[s-65];
          strng[2]=nukwA;
	  strng[3]='\0';
          if(mawra(f)) char_type=mAwrA; else char_type=CONSONENT;
          return(char_type);
          break;
        }
case 'V' : strng[0]=a_to_i[f-65]-1;
           strng[1]='\0';
           if(mawra(f)) char_type=mAwrA; else char_type=CONSONENT;
           return(char_type);
case 'Y' : strng[0]=a_to_i[f-65]+1;
           t=get_ch_frm_str(0,"");
           if(t=='Z')
             {
              strng[1]=nukwA;
              strng[2]='\0';
             }
           else 
             {
              unget_ch_frm_str(t,stdin);
              strng[1]='\0';
             }
         char_type=CONSONENT;
         return(char_type);
default:  unget_ch_frm_str(s,stdin);
          strng[0]=a_to_i[f-65];
	  strng[1]='\0';
          if(mawra(f)) char_type=mAwrA; else char_type=CONSONENT;
          return(char_type);
}
}

/*
main(argc,argv)
int argc;
char *argv[];
{
int ROMAN;
char in_str[1000],out_str[1000];
ROMAN = 0;
DELIMITER='\0';
if(argc < 2)
{
printf("Usage rtod.out strng\n");
exit(0);
}
strcpy(in_str,argv[1]);
printf("set ");
fputs("%",stdout);
printf("out_string  \"");
rtod(in_str,out_str);
printf("%s\"",out_str);
}
*/
