#include <stdio.h>
/*
#include <string.h>
*/
extern void fgetword();
int
my_blk_fbsearch(fp,key,base,nel,width,compar)
char *key;
int base,nel,width;
int (* compar)();
FILE *fp;
{
/* Given the table start address - base,
	 the table size - nel,
         the table width - width,
	 the comparison function - compar,
   this function returns the ptr to the location of the key
   in the table, if it is present else returns a null 
*/
	int low,high,mid,ans,pos;
        int mid_add;
        char mid_key[255];
	low = 0; 
	high = nel-1;
	while (low <= high) {
		mid = (low + high)/2;
                mid_add = (int) base + mid*width;
                fseek(fp,mid_add,0);
                fgetword(fp,mid_key,',');
		ans = (* compar)(key,mid_key);
		/* printf("The string being tested is %s\n",(char *)((int )base+mid*width)); */
		if (ans < 0) high = mid -1;
		else if (ans > 0) low = mid +1;
		else 
                 {
                  pos=mid;
		ans = (* compar)(key,mid_key);
                  while((!ans)&&(pos>0))
	 	  {
                  pos--;
                mid_add = (int) base + pos*width;
                fseek(fp,mid_add,0);
                fgetword(fp,mid_key,',');
		ans = (* compar)(key,mid_key);
                  }
                  if(ans!=0) pos++;
                mid_add = (int) base + pos*width;
                  return(mid_add);
                 }
	}
	return (-1);
}
/*
main()
{
FILE *fp;
char str[10];
int ptr;
if((fp=fopen("suff_info.c","r")) == NULL)
         {
		 printf("ERROR . Can't open suff_info.c for reading\n");
               exit(0);
        }
printf("Enter the string to be searched\n");
scanf("%s",str);
ptr = my_blk_fbsearch(fp,str,3,100,7,strcmp);
if(ptr !=-1)
{
fseek(fp,ptr,0);
getfileword(fp,str);
printf("%s\n",str);
}
else
printf("Not found\n");
}
*/
