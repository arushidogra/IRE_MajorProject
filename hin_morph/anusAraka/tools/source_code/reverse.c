#include <stdio.h>
#include <string.h>

void reverse(str)
char *str;
{
int c,i,j;
for(i=0,j=strlen(str)-1;i<j;i++,j--)
{
 c=str[i];
str[i]=str[j];
str[j]=c;
}
}

/*
main()
{
char word[100];
while(getline(word))
{
if(word[0] == '\0') break;
reverse(word);
printf("%s\n",word);
}
}
*/
