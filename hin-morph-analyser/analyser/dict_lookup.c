/**
 * File Name: dict_lookup.c 
*/

/** dict_lookup
 * This function checks the word in the dictionary 
 * The arguments: 
 * word of char type, db object of GDBM_FILE and ans_ar of 2-dimensional 
 * array of char type
 * Return:void
 */


/* HEADER FILES */
#include <string.h>
#include <stdio.h>
#include <gdbm.h>

#include <fcntl.h>
#include "defn.h"
#include "morph_logger.h"

extern FILE *log_file;
extern char *program_name;

#define FUNCTION "dbm_dict_lookup()"

/**
 * Prototypes of the functions in this file with a file scope
*/
extern void build_struct();
extern char * my_blk_bsearch();

/** dbm_dict_lookup
 * This function checks the word in the dictionary
 * The arguments:
 * word of char type, db object of GDBM_FILE and ans_ar of 2-dimensional
 * array of char type
 */
void dbm_dict_lookup(word,db,ans_ar1)

char  word[WORD_SIZE]; 			    /* given morph word */
GDBM_FILE db;             		    /* GNU database manager includes dbm and ndb
                                             compatability and db is used for opening file */
 char ans_ar1[SmallArray][LargeArray];      /* lexical word */
 {
    datum db_tag,db_out;                    /* datum is function of gdbm , db_tag is key and
                                             db_out is content */

    int loop1;
    /* word , pointer for tmp_str , output word */
    char temp_str[LargeArray], *ptr_tmp,ans_ar[SmallArray][LargeArray];
    db_tag.dptr = word;                      
    db_tag.dsize = strlen(word);
    db_out = gdbm_fetch(db,db_tag);
    /* if(db_out.dptr != '\0') changed for DOS */
	 PRINT_LOG(log_file, "This is dbm_dict_lookup()\n");
  	if(db_out.dsize != 0)        		/* if word size is not equal to zero */
	 {
          strncpy(temp_str,db_out.dptr,db_out.dsize);
	  temp_str[db_out.dsize]='#';
	  temp_str[db_out.dsize+1]='\0';
	  strcpy(ans_ar[0],temp_str);
	  for(loop1=0;;) 			/* check fo null */
	    {
             /* if first char is # then ptr_tmp is null */
	     if((ptr_tmp = strchr(ans_ar[loop1],'#')) == NULL)  /* checks for null */
		    break;
            *ptr_tmp = '\0';
             strcpy(ans_ar[++loop1],ptr_tmp+1);
	     }
           }
	  else ans_ar[0][0] = '\0';  /* place ans_ar to null */

   /* This function creates a specfic structure for the rootword,priority            pdgm and category. it copies the required data from the dictionary */
       	build_struct(word,ans_ar,ans_ar1);  
  }

/** flat_dict_lookup
 * This function checks the word in the dictionary
 * The arguments:
 * word of char type,
 * the table size - nel,
 * the base address - base,
 * the table width - width,
 * the comparison function - compar,
 * this function returns the ptr to the location of the key
 * in the table, if it is present else returns a null db object of GDBM_FILE 
 * and ans_ar of 2-dimensional array of char type
 * Return : void
 */

void flat_dict_lookup(word,base,nel,width,compar,ans_ar)

char *base,*word;                      /*  table start address pointer , word pointer */
int nel,width;			       /*  nel is table size , width is table width */	
int (* compar)();
char ans_ar[SmallArray][LargeArray];
  {
    char * tag_out;			/* char pointer */
    int ans,loop1,loop2;
    tag_out =  (char *)my_blk_bsearch(word,base,nel,width,strcmp);  
    /* This function returns the ptr to the location of the key in the table,
            if it is present  else returns a null */
    loop1=0;
    for(loop1=0;loop1<SmallArray;loop1++) /* checks word is null or not */
       for(loop2=0;loop2<LargeArray;loop2++)
 	   ans_ar[loop1][loop2] = '\0';
       if(tag_out != '\0') /* if search is null ie if ptr fails in pointing  key in the table */
      	{
 	    ans = (* compar) (word,tag_out);
            while(!ans)                                 /* if ans is not true */
             {
	 	for(loop2=0;loop2<width;loop2++)       /* assigns the word to ans_ar */
                   ans_ar[loop1][loop2]=tag_out[loop2];
		ans_ar[loop1][loop2] = '\0';
		loop1++;
		tag_out = tag_out + width;
		ans = (* compar) (word,tag_out);
	      }
          }
	 strcpy(ans_ar[loop1] , "");
     }
/** dict_lookup
 * This function checks the word in the dictionary
 * The arguments:
 * word of char type,
 * the table size - nel,
 * the base address - base,
 * the table width - width,
 * the db object of DBM ,
 * the comparison function - compar,
 * this function returns the ptr to the location of the key
 * in the table, if it is present else returns a null db object of GDBM_FILE
 * and ans_ar of 2-dimensional array of char type
 * Return :void
 */


void dict_lookup(word,DBM_FLAG,db,base,nel,width,compar,ans_ar)

 char *base,*word;    /* base address of table, morph word */
 int nel,width;       /* table size */
 int (* compar)();    /* comparison function  of integer return type */
 char ans_ar[SmallArray][LargeArray];  /* lexical word */
 int DBM_FLAG;        /* dictionary flag, represents 1 for true and 0 for false */
 GDBM_FILE db;        /* global dictionary object db */
  {
   if(DBM_FLAG)      /* if DBM_FLAG is true */
 	dbm_dict_lookup(word,db,ans_ar);
   else            /* if DBM_FLAG is false */
	flat_dict_lookup(word,base,nel,width,compar,ans_ar);
   }
/** prop_noun_dict_lookup
 * This function checks the word in the dictionary
 * The arguments:
 * word of char type,
 * the table size - nel,
 * the base address - base,
 * the table width - width,
 * the comparison function - compar,
 * this function returns the ptr to the location of the key
 * in the table, if it is present else returns a null db object of GDBM_FILE
 * and ans_ar of 2-dimensional array of char type
 * Return : void
 */


void prop_noun_dict_lookup(word,base,nel,width,compar,ans_ar)

char *base,*word;
int nel,width;
int (* compar)();
char ans_ar[SmallArray][LargeArray];
 {
    char * tag_out;
    int ans,loop1,loop2;
    /* This function returns the ptr to the location of the key in the table,                              if it is present else returns a null */
    tag_out =  (char *)my_blk_bsearch(word,base,nel,width,strcmp);
    loop1=0;
       for(loop1=0;loop1<SmallArray;loop1++) /* intialising the objec ans_Ar to null */
	 for(loop2=0;loop2<LargeArray;loop2++)
	   ans_ar[loop1][loop2] = '\0';
	if(tag_out != '\0')    /* if tag_out is not equal to null */
	   {
              ans = (* compar) (word,tag_out);
		while(!ans) /* if ans is false */
		{
	          for(loop2=0;loop2<width;loop2++) /* if loop is less than width of the table */
		    ans_ar[loop1][loop2]=tag_out[loop2];
                  ans_ar[loop1][loop2] = '\0';
	          loop1++;
	          tag_out = tag_out + width;
		  ans = (* compar) (word,tag_out);
		}
             }
           
        strcpy(ans_ar[loop1] , "");
  }
