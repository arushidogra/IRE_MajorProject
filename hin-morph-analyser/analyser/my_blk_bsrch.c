/**
 * File Name : my_blk_bsrch.c.c
 */



/** Fuction : my_blk_bsrch
  * This function returns the ptr to the location of the key in the table, if it is present 
  * else returns a null
  * It takes arguments: key of char type ,base of char type ,nel of int type 
  * width of int type and compar is function with integer return type
  * Return : void 
  */
void *my_blk_bsearch(key,base,nel,width,compar)
	char *base,*key;
	int nel,width;
	int (* compar)();
	{
/* Given the table start address - base,
	 the table size - nel,
         the table width - width,
	 the comparison function - compar,
   this function returns the ptr to the location of the key
   in the table, if it is present else returns a null 
*/
	int low,high,mid,ans,pos;
	low = 0; 
	high = nel-1;
	while (low <= high)  /* executes only when low < = high */
             {
		mid = (low + high)/2;
		ans = (* compar)(key,(char *)(base+mid*width));
		/* printf("The string being tested is %s\n",(char *)(base+mid*width)); */
		if (ans < 0)  /* checks for ans is <0 */
                   high = mid -1;
		else if (ans > 0)   
                    low = mid +1;
		      else 
                        {
                         pos=mid;
              		  ans = (* compar)(key,(char *)(base+pos*width));
              		  while((!ans)&&(pos>0))
	 	   	    {
	                      pos--;
		              ans = (* compar)(key,(char *)(base+pos*width));
                  	     }
	                  if(ans!=0) pos++;
        	          return((void *) (base + pos*width));
                       }
	        }
	return ((void *) '\0');
      }
