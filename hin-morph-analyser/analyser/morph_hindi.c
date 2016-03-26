/**
 * File Name : morph_hindi.c
*/

/** Function : fun_morph
 * Description: This function is the main functuon. It extracts suffixes and calls different      * routines for analysis
 * Input Arguments: 
 * morph of char array,swit1 of int type ,fpt1 filepointer ,fp_pdgm filepointer
 * DBM_FLAG of int type ,db_lex  filepointer of DBM ,db_suff filepointer of DBM ,
 * ans_ar object of structure ans_struct
 * Return: void
 */
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <gdbm.h>

#include "struct1.h"
#include "struct.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern char *log_messg;
extern void cp_suff_add_struct();

#define FUNCTION "fun_morph()"

extern int FINDONCE; 			/* if word is present FINDONCE will be 1 */
extern int DEFAULT_PARADIGM; 		/* default paradigm */
extern int ALWAYS_DEFAULT_PARADIGM;	/* considers only guessed paradigm even pdgm is there */
extern int DBM_FLAG; 			/* check for dictionary if true then it is present */ 
extern int WORD_NUM;			/* word number */
extern int DEBUG;
extern int INFLTNL;

extern int sizeof_lex; 			/* size of lexical value */
extern int sizeof_prop_noun_lex;        /* size of proper noun lex */
extern int sizeof_suff_add;		/* size of suffix to be added */

extern struct lex_info lex_ar[];        /* object of structure lex_info , where lex_info
                                             contains info of root,pdgm,cat etc */
extern struct lex_info prop_noun_lex_ar[]; /*  proper noun object of structure lex_info , 
                                           where lex_info contains info of root,pdgm,cat etc */

extern struct suff_add_info suff_add_info_ar[];  /* object of suff_add_info structure, where it
                                                   contains suffix,add,pdgm[WORD_SIZE],
                                                    category, offset */
/**
 * Prototypes of the functions in this file with a file scope
 */
extern void get_paradigm();
extern void get_pdgm_info();
extern void get_suff();
extern void get_suff_info();
extern int dbm_suff_tab_lookup();
extern void *my_blk_bsearch();
extern void prop_noun_dict_lookup();
extern void cp_to_struct();
// extern void cp_to_struct_chk_pdgm();
extern void dict_lookup();
extern void verify_root();
extern void print_default_ans();


void fun_morph(morph,swit1,fpt1,fp_pdgm,DBM_FLAG,db_lex,db_suff,ans_ar)
FILE *fp_pdgm,*fpt1;
GDBM_FILE db_lex,db_suff;	/* GNU database manager includes dbm and ndb
                                    compatability and db is used for opening file */
char morph[Morphsize];		/* morph input word */
int DBM_FLAG,swit1;    		/* swit is switch , DBM_FLAG is checks for Dictionary 
                                   is present or not */
struct ans_struct ans_ar[SmallArray]; /* ans_struct structure ,it contains of root,offset,
                                        aux_verb,pdgm */
{
	int morph_size,ISNUM;     /* morph size, isnumeral */
	//char morph[Morphsize];		/* morph input word */
	int loop1,loop2,l,pos,pos1,offset,loop;    /*pos and pos1  is position values */
	int fseek_ptr;      /* pointer position for suffix */
        /* suffix of word , guessed root, temp suff */
	char suff[SUFFWORDSIZE],guessed_root[SUFFWORDSIZE],tmp_suff[SUFFWORDSIZE];
        /* paradigm , category, guessed paradigm */
	char pdgm[WORD_SIZE],category[CATEGORYWORDSIZE],my_pdgm[WORD_SIZE];
	char ans_ar1[SmallArray][LargeArray];  /* ans_ar1 is lexical morph word */
	char tmp_wrd[SUFFWORDSIZE];    /*temp suff */
	struct lex_info  ans_table[SmallArray];    /* gives lexical info of input word */
	char *tag_suff = NULL;    /* tag suffix */
	struct suff_add_info tag_suff_ar[Arraysize],dummy;
	//int sizeof_dummy;    /* intial size of suffix */
	int AVY_srch();
        int is_in_db = 0;
        PRINT_LOG(log_file, "This is fun_morph()\n");
	
	sprintf(log_messg, "INFO: fun_morph"); PRINT_LOG(log_file, log_messg);
	pos = 0;
	//sizeof_dummy = sizeof(dummy);

	/* intializing root,pdgm,cat to null */
	for(loop1=0;loop1<Arraysize;loop1++)  
        {
		ans_ar[loop1].root[0]='\0';
		ans_ar[loop1].offset = -2;
		ans_ar[loop1].aux_verb[0] = '\0';
		ans_ar[loop1].pdgm[0] = '\0';
	}
	/* calling routine for finding if given word is avy */
       /* This function checks whether the given word is Avy or not.If it is true
          it returns the numeric value. */
	 ISNUM = AVY_srch(morph);
	/*
	 AVY_srch returns
	 -1 if the word is avy
	 -2 if the word is not a number & not an avy
	 -3 if the word is a numeral
	 */

	if (ISNUM != -2) /* checks for isnum is equal to-2 or not */
	{
		 strcpy(ans_ar[pos].root,morph);
		 ans_ar[pos].offset = ISNUM;
		 strcpy(ans_ar[pos].aux_verb,"");
		 strcpy(ans_ar[pos].pdgm,"");
		sprintf(log_messg, "INFO: Word is a NUMERAL or AVYAYA |%s|", ans_ar[pos].root); PRINT_LOG(log_file, log_messg);
		 pos++;
		 return;
	}
	if (ISNUM != -3) /* if given word is not a numeral */
	{
		suff[0]='\0';
		morph_size = strlen(morph);
		for(loop=0;loop<2 && !pos;loop++) /* loop not les than 2 and not equal to pos */
                {
 			if(!loop)  			/* if loop is false */
                           INFLTNL = 1;
                        else
                           INFLTNL = 0;
			 for(l= morph_size;l>=0;l--)  	/* checks for l size >0 */
                         {
                               if(l==morph_size)   	/* checks for l value is equal to morph_size */
                                 { suff[0]='\0';}
                               else
			/* This function concatenates the root word with the suffix */
		 	get_suff(morph,suff,l);
			sprintf(log_messg, "INFO: Suffix stripping|%s|%s|%d|", morph, suff, l); PRINT_LOG(log_file, log_messg);
				if(DBM_FLAG)  /* checks for DBM_FLAG is true or not */
			       {
			       		if(suff[0] == '\0')  /*executes when suff[0] is null */
					strcpy(suff,"0");
                                        /* This function checks the suffix word is
                                        present in the suff file */
					is_in_db = dbm_suff_tab_lookup(suff,db_suff, tag_suff_ar);
					sprintf(log_messg, "INFO: Looking into Suffix table|suff=%s|db_suff=%p|tag_suff=%s|", \
						suff, db_suff, tag_suff); PRINT_LOG(log_file, log_messg);
				      if(!strcmp(suff,"0")) /* compares  for suff value with 0 and executes only when false */
                                          strcpy(suff,"");
				}
				/*
				 * This function returns the ptr to the location of the key in the table, 
				 * if it is presentelse returns null 
				 */ 
			        else
			tag_suff = (char *)my_blk_bsearch(suff,suff_add_info_ar->suff,sizeof_suff_add,sizeof(suff_add_info_ar[0]),strcmp);
				sprintf(log_messg, "INFO: Bulk search for tag_suffix|tag_suff=%s|", tag_suff); PRINT_LOG(log_file, log_messg);
   			
					loop1=0;
						/* executes until tag_suff!=null */
				while(tag_suff!=NULL) {
                                             /* This function adds the suffix to the root word */
				              cp_suff_add_struct(&tag_suff_ar[loop1],tag_suff);
					      tag_suff+=sizeof(dummy);
					     /* compares suffix value with guessed suff  */
				              if(strcmp(tag_suff_ar[loop1].suff,suff))
                                                  break;
                                              loop1++;
				} /* if(tag_suff!='\0') */
				loop2=0;
						  /* checks for loop1>0 */
				          if(loop1>0 || is_in_db) {
					       strcpy(tmp_suff,tag_suff_ar[loop2].suff);
					/*executes only when suff and tmp_sff are not same */
				while(!strcmp(tmp_suff,suff)) {
					strncpy(guessed_root,morph,l);
					guessed_root[l]='\0'; 
					strcat(guessed_root,tag_suff_ar[loop2].add);

					/* This function checks the word in the dict */ 
					prop_noun_dict_lookup(guessed_root,prop_noun_lex_ar->word,sizeof_prop_noun_lex,
											sizeof(prop_noun_lex_ar[0]),strcmp,ans_ar1);

					sprintf(log_messg, "INFO: Proper Noun Dictionary lookup|%s|", prop_noun_lex_ar->word); PRINT_LOG(log_file, log_messg);
						        pos1 = 0;
/* This function copies data ie Priority , pdgm,cat,word to the structure */

							cp_to_struct(ans_ar1,ans_table,&pos1); 
                                 /* This function checks the word in the dictionary */
							dict_lookup(guessed_root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar1);
/* This function copies data ie Priority , pdgm,cat,word to the structure */
							cp_to_struct(ans_ar1,ans_table,&pos1);   						         strcpy(tmp_wrd,guessed_root);
							fseek_ptr = tag_suff_ar[loop2].ptr;
							for(loop1=0;loop1<tag_suff_ar[loop2].no_of_entries ; loop1++) /* exeutes until loop1 <no. of entries */
						        {
							      strcpy(guessed_root,tmp_wrd);
							      get_pdgm_info(fp_pdgm,pdgm,category,&offset,&fseek_ptr);
/* This function compares the guessed root , paradigm,category with the data in the dictionary */
							      verify_root(INFLTNL,guessed_root,pdgm,category,offset,ans_table,ans_ar,&pos,DBM_FLAG,db_lex);
 						         }
                          				    if(ALWAYS_DEFAULT_PARADIGM || ((ans_table[0].word[0] == '\0') &&(DEFAULT_PARADIGM))) /* gets finall output only when ALWAYS_DEFAULT_PARADIGM is true or word !=null and default pdgm is true */
							    {
							    	if(suff[0]!='\0') /*checks for suff != null */
								{

  /* This function takes the last letter of the word and checks the guessed paradigm from
    the paradigm list using the switch case */	                 
                                                            	   	get_paradigm(guessed_root,my_pdgm); 
								      	if(!strcmp(my_pdgm,pdgm))/* checks pdgm is not same as of guessed pdgm */
									 {
								          strcpy(ans_ar[pos].root,guessed_root);
  							                  ans_ar[pos].offset = offset;
								          strcpy(ans_ar[pos].aux_verb,"");
							                  strcpy(ans_ar[pos].pdgm,"");
                                                                          pos++;
							                 }
							       	  }
							     }
                                                             loop2++;
                                                             strcpy(tmp_suff,tag_suff_ar[loop2].suff);
							}/* end of the while loop*/
                                        }
                              }
                      }/* end of the for loop */
		      if(pos > 0)  /* checks for pos > 0 */
                        FINDONCE = 1;
                      else      /* executes when pos is <0 */
                      	FINDONCE = 0;
			if (!FINDONCE) /* checks for FINDONCE is false */
			{
				if (ALWAYS_DEFAULT_PARADIGM || DEFAULT_PARADIGM)
/* This function gives the output in horizontal way when there is singular direct case */
                                  print_default_ans(morph);  
		        }
	 }
	sprintf(log_messg, "INFO: end of if loop Noun Dictionary lookup"); PRINT_LOG(log_file, log_messg);
	strcpy(ans_ar[pos].root,morph);
	ans_ar[pos].offset = -2; /* End of ar marker */
	strcpy(ans_ar[pos].aux_verb,"");
	strcpy(ans_ar[pos].pdgm,"");
	sprintf(log_messg, "INFO: values from fun_morph are|%s|%s|%s|", ans_ar[pos].root, ans_ar[pos].aux_verb, ans_ar[pos].pdgm); PRINT_LOG(log_file, log_messg);
}/*end of the fun_morph*/	
