
/* this program converts the text in devanagri to roman 
 & vice versa.
 dtor :
 every devanagari word starts with nukwA.
 halanta is explicitly written by appending a halanta
 the characters Q,H,f & F (iitk_code) are mapped to   p,B,G & K respectively followed by nukwA ,in devanagari.
 
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

rtod()
{
int prev_type,curr_type;
char str[3];
prev_type=SP_CHAR;
curr_type=SP_CHAR;
while(curr_type!=EOF)
{
curr_type=get_gist_code(str);
switch(curr_type)
{
case a_char :   if(prev_type==SP_CHAR)
                {
                printf("%c",nukwA);
                printf("%s",str);
                }
                else if (prev_type==mAwrA)
                      printf("%s",str);
                break;
case mAwrA:     if(prev_type==SP_CHAR)
               {
                printf("%c",nukwA);
/*
                if((str[0]!=visarg_code) && ( str[0]!=Q_code)) printf("%c",a_code);
*/
                if(str[0]!=visarg_code) printf("%c",a_code);
               }
                if(((prev_type==a_char)||(prev_type==mAwrA))&&(str[0]!=visarg_code)&&(str[0]!=Q_code)&&(str[0]!=chandra_bindu)&&(str[0]!=avagraha_code))
                printf("%c",a_code);
                printf("%s",str);
                break;
case CONSONENT: if(prev_type==SP_CHAR)
                printf("%c",nukwA);
                if(prev_type==CONSONENT)
                printf("%c",halanwa);
                printf("%s",str);
                break;
case SP_CHAR: if(prev_type==CONSONENT)
              printf("%c",halanwa);
	      printf("%s",str);
              break;
}
prev_type=curr_type;
}
return;
}

int get_gist_code(strng)
char strng[3];
{
int f;
char s,t;
int char_type;
f=getchar();
if(f==DELIMITER)
{
printf("%c",f);
f=getchar();
while((f!=DELIMITER) && (f != EOF))
{
printf("%c",f);
f=getchar();
}
printf("%c",f);
strng[0]='\0';
if(f==EOF)
{
char_type=EOF;
return(char_type);
}
else return(SP_CHAR);
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

s=getchar();
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
           t=getchar();
           if(t=='Z')
             {
              strng[1]=nukwA;
              strng[2]='\0';
             }
           else 
             {
              ungetc(t,stdin);
              strng[1]='\0';
             }
         char_type=CONSONENT;
         return(char_type);
default:  ungetc(s,stdin);
          strng[0]=a_to_i[f-65];
	  strng[1]='\0';
          if(mawra(f)) char_type=mAwrA; else char_type=CONSONENT;
          return(char_type);
}
}



int get_iitk_code(strng)
char strng[3];
{
int f;
char s,t;
int char_type;
f=getchar();
if(f==DELIMITER)
{
printf("%c",f);
f=getchar();
while((f!=DELIMITER) && (f != EOF))
{
printf("%c",f);
f=getchar();
}
printf("%c",f);
strng[0]='\0';
if( f == EOF)
{
	   char_type=EOF;
           return(char_type);
}
else return(SP_CHAR);
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
case F_code : s=getchar();
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
              ungetc(s,stdin);
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
              s=getchar();
              if(s==nukwA) {
                           strng[2]='Z';
                           strng[3]='\0';
                          }
              else {
              ungetc(s,stdin);
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
case a_code: s=getchar();
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
             ungetc(s,stdin);
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
              s=getchar();
              if(s==nukwA) { strng[0]=i_to_a[f-65];
                           strng[1]='Z';
                           strng[2]='\0';
                          }
              else {
              ungetc(s,stdin);
              strng[0]=i_to_a[f-65];
              strng[1]='\0';}
              }
              return(char_type);
}
}



dtor()
{
int prev_type,curr_type;
char str[3];
prev_type=SP_CHAR;
curr_type=SP_CHAR;
while(curr_type!=EOF)
{
curr_type=get_iitk_code(str);
if((prev_type==CONSONENT)&&((curr_type==CONSONENT)||(curr_type==SP_CHAR)||(curr_type==SP_MAWRA)||(curr_type==a_mawra)))
  {
   printf("a");
   printf("%s",str);
  }
else printf("%s",str);
prev_type=curr_type;
}
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
int ROMAN;
ROMAN = 0;
DELIMITER='\0';
if(argc > 1)
{
   if (index(argv[1] , 'r')) ROMAN =1;
   if (index(argv[1] , 'd')) DELIMITER= argv[1][1];
}
if(DELIMITER=='\0') DELIMITER ='@';
if(ROMAN) dtor(); else rtod();
}

