/***** THIS IS THE MAIN FUNCTION. IT EXTRACTES SUFFIXES  *******/
/***** & CALLS DIFFERENT ROUTINES REQUIRED FOR ANALYSIS *******/ 
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"

extern int FINDONCE;
extern int DEFAULT_PARADIGM;
extern int ALWAYS_DEFAULT_PARADIGM;
extern int DBM_FLAG;
extern int WORD_NUM;
extern int sizeof_suff;
extern int sizeof_lex;
extern int sizeof_prop_noun_lex;
extern int sizeof_suff_add;

extern struct lex_info lex_ar[];
extern struct lex_info prop_noun_lex_ar[];
extern struct suff_add_info suff_add_info_ar[];

extern void get_paradigm();
extern void get_pdgm_info();
extern void get_suff();
extern void get_suff_info();
extern print_default_ans();
extern struct suff_add_info *dbm_suff_tab_lookup();

int fun_morph(morph,swit1,fpt,fp_pdgm,DBM_FLAG,db_lex,db_suff,ans_ar,RECURSION)
FILE *fpt,*fp_pdgm;
#ifdef GNU
GDBM_FILE db_lex,*db_suff;
#else
DBM *db_lex,*db_suff;
#endif

char morph[Morphsize];
int swit1,DBM_FLAG,*RECURSION;
struct ans_struct ans_ar[100];
{
int lex_found,morph_size,ISNUM;
int i,j,k,l,ptr,pos,pos1,offset;
int no_of_entries,len,len1;
int fseek_ptr;
char suff[SUFFWORDSIZE],guessed_root[SUFFWORDSIZE],tmp_suff[SUFFWORDSIZE];
char pdgm[WORD_SIZE],category[CATEGORYWORDSIZE],my_pdgm[WORD_SIZE],lex_pdgm_lst[WORD_SIZE];
char ans_ar1[100][200];
char tmp_wrd[SUFFWORDSIZE];
struct lex_info  ans_table[100];
struct suff_add_info *tag_suff;
int AVY_srch();

pos = 0;

/**********calling routine for finding if given word is avy*******/

ISNUM = AVY_srch(morph);
 /*
  AVY_srch returns
     -1 if the word is avy
     -2 if the word is not a number & not an avy
     -3 if the word is a numeral
 */

/*****************************************************************/


if (ISNUM != -2)
 {
 strcpy(ans_ar[pos].root,morph);
 ans_ar[pos].offset = ISNUM;
 strcpy(ans_ar[pos].aux_info,"");
pos++;
 }
 if (ISNUM != -3) /***if given word is not a numeral ***/
{
suff[0]='\0';
morph_size = strlen(morph);
for(l= morph_size;l>=0;l--)
      {
       if(l==morph_size) suff[0]='\0';
      else get_suff(morph,suff,l);
       tag_suff =(struct suff_add_info *)  my_blk_bsearch(suff,suff_add_info_ar->suff,sizeof_suff_add,sizeof(suff_add_info_ar[0]),strcmp);
       if(tag_suff!='\0')
       {
       strcpy(tmp_suff,tag_suff->suff);
       while(!strcmp(tmp_suff,suff))
       {
	strncpy(guessed_root,morph,l);
	guessed_root[l]='\0';
	strcat(guessed_root,tag_suff->add);
	prop_noun_dict_lookup(guessed_root,prop_noun_lex_ar->word,sizeof_prop_noun_lex,sizeof(prop_noun_lex_ar[0]),strcmp,ans_ar1);
        pos1 = 0;
	cp_to_struct(ans_ar1,ans_table,&pos1);
	dict_lookup(guessed_root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar1);
	cp_to_struct(ans_ar1,ans_table,&pos1);
       strcpy(tmp_wrd,guessed_root);
       fseek_ptr = tag_suff->ptr;
       for(i=0;i<tag_suff->no_of_entries ; i++)
          {
       strcpy(guessed_root,tmp_wrd);
       get_pdgm_info(fp_pdgm,pdgm,category,&offset,&fseek_ptr);
       if(index(pdgm,'?')) /* if it is a vwl_hrmn_pdgm modify the guessed root by changing the vowels so as to bring in vowel harmony */
	{
	 vwl_harmony(guessed_root,vwl_hrmn_wrd);
	 if((vwl_hrmn_wrd[0] != '\0') && strcmp(guessed_root,vwl_hrmn_wrd))
          {
	  dict_lookup(vwl_hrmn_wrd,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar1);
	  cp_to_struct_chk_pdgm(ans_ar1,ans_table,&pos1,pdgm);
	  }
	 strcpy(guessed_root,vwl_hrmn_wrd);
	}
/*
	match_in_dict(guessed_root,pdgm,category,offset,ans_table,ans_ar,&pos); 
*/
	verify_root(guessed_root,pdgm,category,offset,ans_table,ans_ar,&pos,1,fpt,fp_pdgm,DBM_FLAG,db_lex);
           }
       if(ALWAYS_DEFAULT_PARADIGM || ((ans_table[0].word[0] == NULL) &&(DEFAULT_PARADIGM)))
             {
		if(suff[0]!='\0') 
		{
              	get_paradigm(guessed_root,my_pdgm);
	      	if(!strcmp(my_pdgm,pdgm))
		 {
		strcpy(ans_ar[pos].root,guessed_root);
		ans_ar[pos].offset = offset;
		strcpy(ans_ar[pos].aux_info,"");
		pos++;
		}
    	        }
	    }
         *tag_suff++;
         strcpy(tmp_suff,tag_suff->suff);
    }
   }
   }
if(pos > 0) FINDONCE = 1; else FINDONCE = 0;
if (!FINDONCE)
 {
        if (swit1 == 0)
		fprintf(fpt,"w%d %s\n",WORD_NUM,morph);
	if (ALWAYS_DEFAULT_PARADIGM || DEFAULT_PARADIGM)
    print_default_ans(morph);
 }
}
strcpy(ans_ar[pos].root,morph);
ans_ar[pos].offset = -2; /* End of ar marker */
strcpy(ans_ar[pos].aux_info,"");
}
