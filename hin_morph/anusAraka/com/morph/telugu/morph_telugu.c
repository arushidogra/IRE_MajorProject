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
extern int DEBUG;
extern int INFLTNL;

extern int sizeof_lex;
extern int sizeof_prop_noun_lex;
extern int sizeof_suff_add;
extern int direct_ans_flag;

extern struct lex_info lex_ar[];
extern struct lex_info prop_noun_lex_ar[];
extern struct suff_add_info suff_add_info_ar[];

extern void get_paradigm();
extern void get_pdgm_info();
extern void get_suff();
extern char *dbm_suff_tab_lookup();
extern void * my_blk_bsearch();
extern void prop_noun_dict_lookup();
extern void cp_to_struct();
extern void cp_to_struct_chk_pdgm();
extern void dict_lookup();
extern void vwl_harmony();
extern void verify_root();
extern void print_default_ans();

void
fun_morph(morph,fp_pdgm,DBM_FLAG,db_lex,db_suff,ans_ar)
FILE *fp_pdgm;
#ifdef GNU
GDBM_FILE db_lex,*db_suff;
#else
DBM *db_lex,*db_suff;
#endif

char morph[Morphsize];
int DBM_FLAG;
struct ans_struct ans_ar[20];
{
int morph_size,ISNUM;
int i,i1,l,pos,pos1,offset,loop;
int fseek_ptr;
char suff[SUFFWORDSIZE],guessed_root[SUFFWORDSIZE],tmp_suff[SUFFWORDSIZE];
char pdgm[WORD_SIZE],category[CATEGORYWORDSIZE],my_pdgm[WORD_SIZE];
char ans_ar1[100][2000];
char vwl_hrmn_wrd[SUFFWORDSIZE],tmp_wrd[SUFFWORDSIZE];
struct lex_info  ans_table[100];
char *tag_suff;
struct suff_add_info tag_suff_ar[20],dummy;
int sizeof_dummy;

int AVY_srch();

pos = 0;
direct_ans_flag = 0;
sizeof_dummy = sizeof(dummy);

/**********calling routine for finding if given word is avy*******/

for(i=0;i<20;i++)
{
ans_ar[i].root[0]='\0';
ans_ar[i].offset = 0;
ans_ar[i].aux_verb[0] = '\0';
ans_ar[i].pdgm[0] = '\0';
}
/* ISNUM = AVY_srch(morph,ans_ar,&pos); */
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
 strcpy(ans_ar[pos].aux_verb,"");
 strcpy(ans_ar[pos].pdgm,"");
 pos++;
 }

 if (ISNUM !=  -3) /***if given word is not a numeral ***/
{
suff[0]='\0';
morph_size = strlen(morph);
for(loop=0;loop<2 && !pos;loop++){
if(!loop) INFLTNL = 1; else INFLTNL = 0; 
for(l= morph_size;l>=0;l--)
      {
       /* If the given word is found in the dict. then do not analyse further.
       e.g. maMcivAdu -/-> maMci + vAdu, if maMcivAdu is found in the dict. */
/*       if((l== morph_size-1) && (pos > 0)) { goto LAST;}  */

       if(l==morph_size) suff[0]='\0';
       else get_suff(morph,suff,l);
       if(DBM_FLAG)
       {
       if(suff[0] == '\0') strcpy(suff,"0");
       tag_suff =  dbm_suff_tab_lookup(suff,db_suff);
       if(!strcmp(suff,"0")) strcpy(suff,"");
       }
       else
       tag_suff = (char *)my_blk_bsearch(suff,suff_add_info_ar->suff,sizeof_suff_add,sizeof(suff_add_info_ar[0]),strcmp);
       i=0;
       while(tag_suff!=NULL)
        {
          cp_suff_add_struct(&tag_suff_ar[i],tag_suff);
          tag_suff+=sizeof(dummy);
          if(strcmp(tag_suff_ar[i].suff,suff)) break;
          i++;
        }
/*
       if(tag_suff!='\0')
*/
       i1=0;
       if(i>0)
       {
       strcpy(tmp_suff,tag_suff_ar[i1].suff);
       while(!strcmp(tmp_suff,suff))
       {
	strncpy(guessed_root,morph,l);
	guessed_root[l]='\0';
	strcat(guessed_root,tag_suff_ar[i1].add);
	prop_noun_dict_lookup(guessed_root,prop_noun_lex_ar->word,sizeof_prop_noun_lex,sizeof(prop_noun_lex_ar[0]),strcmp,ans_ar1);
        pos1 = 0;
	cp_to_struct(ans_ar1,ans_table,&pos1);
	dict_lookup(guessed_root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar1);
        cp_to_struct(ans_ar1,ans_table,&pos1);
       strcpy(tmp_wrd,guessed_root);
       fseek_ptr = tag_suff_ar[i1].ptr;
       for(i=0;i<tag_suff_ar[i1].no_of_entries ; i++)
          {
       strcpy(guessed_root,tmp_wrd);
       get_pdgm_info(fp_pdgm,pdgm,category,&offset,&fseek_ptr);
       if(index(pdgm,'?')) /* if it is a vwl_hrmn_pdgm modify the guessed root by changing the vowels so as to bring in vowel harmony */
	{
	 /*vwl_harmony(guessed_root,vwl_hrmn_wrd);*/
	 vwl_harmony(guessed_root,pdgm,vwl_hrmn_wrd);
	 if((vwl_hrmn_wrd[0] != '\0') && strcmp(guessed_root,vwl_hrmn_wrd))
          {
	  dict_lookup(vwl_hrmn_wrd,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar1);
	  cp_to_struct_chk_pdgm(ans_ar1,ans_table,&pos1,pdgm);
	  }
	 strcpy(guessed_root,vwl_hrmn_wrd);
	}
	verify_root(INFLTNL,guessed_root,pdgm,category,offset,ans_table,ans_ar,&pos,DBM_FLAG,db_lex);
/*
        if( DEBUG && ( pos > 0)) {
           printf("%s\n",ans_ar->root);
	   exit(2);
	 }
*/
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
		strcpy(ans_ar[pos].aux_verb,"");
		strcpy(ans_ar[pos].pdgm,pdgm);
		pos++;
		}
    	        }
	    }
/*
         *tag_suff++;
*/
         i1++;
         strcpy(tmp_suff,tag_suff_ar[i1].suff);
    }
   }
   }
 }
/*LAST:*/
if(pos > 0) FINDONCE = 1; else FINDONCE = 0;
if (!FINDONCE)
 {
	if (ALWAYS_DEFAULT_PARADIGM || DEFAULT_PARADIGM)
    print_default_ans(morph);
 }
}
strcpy(ans_ar[pos].root,morph);
ans_ar[pos].offset = -2; /* End of ar marker */
strcpy(ans_ar[pos].aux_verb,"");
strcpy(ans_ar[pos].pdgm,"");
}
