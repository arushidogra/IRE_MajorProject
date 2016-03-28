
/* this program converts the text in devanagri to roman 
 & vice versa.
 dtor :
 every devanagari word starts with nukwA.
 halanta is explicitly written by appending a halanta
 the characters Q,H,f & F (iitk_code) are mapped to   p,B,G & K respectively followed by nukwA ,in devanagari.
 
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

int sp_char(ch)
unsigned char ch;
{
if(((ch<65)||(ch>122)||((ch>90)&&(ch<97)))&&(ch!=DELIMITER))
return 1;
else return 0;
}

int get_iitk_code(strng)
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
switch(f)
{
case EOF:  strng[0]='\0';
	   char_type=EOF;
           return(char_type);
case nukwA: strng[0]='\0';
            char_type=NUKWA;
            return(char_type);
case halanwa: strng[0]='\0';
              char_type=HALANWA;
              return(char_type);
case avagraha_code:
case Q_code:
case f_code : 
case visarg_code:
case F_code : s=get_ch_frm_str(0,"");
              if(s==nukwA)
              {
              switch(f)
              {
              case f_code: strng[0]='f';
                           char_type=CONSONENT;
                           break;
              case F_code: strng[0]='F';
                           char_type=CONSONENT;
                           break;
              case Q_code:strng[0]='Q';
                          char_type=mAwrA;
                           break;
              case visarg_code:strng[0]='H';
                               char_type=SP_MAWRA;
                               break;
              case avagraha_code: strng[0]='Z';
                                  char_type=mAwrA;
                                  break;
              }
              strng[1]='\0';
              return(char_type);
              }
              else 
              {
              unget_ch_frm_str(s,stdin);
/*
	      if(f == avagraha_code)
	        {
		strng[0]='Z';
                strng[1]='\0';
		char_type=mAwrA;
                return(char_type);
		}
		else
*/
		{
              strng[0]=i_to_a[f-65];
              strng[1]='\0';
              if(f=='B')char_type=SP_MAWRA;
/*
              else if((gist_mawra(f))||(f=='A')||(f == avagraha_code))char_type=mAwrA;
*/
              else if((gist_mawra(f))||(f=='A'))char_type=mAwrA;
              else char_type=CONSONENT;
              return(char_type);
              }
              }
case lY_code:
case rY_code: 
             strng[0]=i_to_a[f-65-1];
             strng[1]='Y';
              s=get_ch_frm_str(0,"");
              if(s==nukwA) {
                           strng[2]='Z';
                           strng[3]='\0';
                          }
              else {
              unget_ch_frm_str(s,stdin);
              strng[2]='\0';}
             char_type=CONSONENT;
             return(char_type);
case oV_code:
case eV_code:
             strng[0]=i_to_a[f-65+1];
             strng[1]='V';
             strng[2]='\0';
             char_type=mAwrA;
             return(char_type);
case a_code: s=get_ch_frm_str(0,"");
             if(gist_mawra(s))
             {
             switch(s)
	     {
		case oV_code:
		case eV_code:
		             strng[0]=i_to_a[s-65+1];
		             strng[1]='V';
		             strng[2]='\0';
		             char_type=a_mawra;
		             return(char_type);
	        default:    strng[0]=i_to_a[s-65];
                            strng[1]='\0';
		            char_type=a_mawra;
		            return(char_type);
             }
             }
             else
             {
             unget_ch_frm_str(s,stdin);
             strng[0]=i_to_a[f-65];
             strng[1]='\0';
             char_type=a_char;
             return(char_type);
             }
default     : if(sp_char(f)) 
              {
              strng[0]=f;
              strng[1]='\0';
              char_type=SP_CHAR;
              }
              else 
              {
              if(gist_mawra(f)) char_type=mAwrA;
              else if((f=='B')||(f=='A')) char_type=SP_MAWRA;
              else char_type=CONSONENT;
              s=get_ch_frm_str(0,"");
              if(s==nukwA) { strng[0]=i_to_a[f-65];
                           strng[1]='Z';
                           strng[2]='\0';
                          }
              else {
              unget_ch_frm_str(s,stdin);
              strng[0]=i_to_a[f-65];
              strng[1]='\0';}
              }
              return(char_type);
}
}



dtor(in_strng,out_strng)
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
curr_type=get_iitk_code(str);
if((prev_type==CONSONENT)&&((curr_type==CONSONENT)||(curr_type==SP_CHAR)||(curr_type==SP_MAWRA)||(curr_type==a_mawra)))
  {
		put_ch_in_str(1,"%c",'a');
                put_str_in_str(1,"%s",str);
  }
else put_str_in_str(1,"%s",str);
prev_type=curr_type;
}
put_str_in_str(2,"%s",out_strng);
return;
}

int gist_mawra(ch)
unsigned char ch;
{
if((ch>=mawra_begin)&&(ch<=mawra_end)) return 1; else return 0;
}



main(argc,argv)
int argc;
char *argv[];
{
char in_str[1000],out_str[1000];
int ROMAN;
ROMAN = 0;
DELIMITER='\0';
if(argc < 2)
{
printf("Usage rtod.out strng\n");
exit(0);
}
strcpy(in_str,argv[1]);
dtor(in_str,out_str);
printf("%s\n",out_str);
}
