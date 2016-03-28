#include<stdio.h>
#include<string.h>

get_sentence(s_ptr)
char *s_ptr;
{
char c,s;
c=getchar();
while (c!=EOF)
{
*s_ptr++=c;
 if((c=='.')||(c=='!')||(c=='?'))
  {
   c=getchar();
/* copy all special characters */
  while(sp_char(c))
   {
   *s_ptr++=c;
   c=getchar();
   }

  /* check for next two blank spaces  or a newline */

  if((c!=EOF)&&(c!='\n')) *s_ptr++=c;
else{ *s_ptr++='\n';*s_ptr='\0'; return;}
  if (c==' ') 
   { s=getchar();
     if((s!=EOF)&&(s!='\n'))*s_ptr++=s;  /* ignore  NEWLINE */
     if (s==EOF) { *s_ptr++='\n';*s_ptr='\0'; return;}
     if(s==' ')
      {
      *s_ptr++='\n';
      *s_ptr='\0';
      return ;
      }
    }
}
    c=getchar(); 
}
}

int sp_char(ch)
char ch;
{
if((ch==')')||(ch==']')||(ch=='"')||(ch=='`')) return 1; else return 0;
}
