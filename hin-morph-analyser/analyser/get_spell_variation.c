/*
Functions ------------------------- Rules
Z_replace() s/Z//g
M_rep_z()   s/([EeoOiI])M/\1z/g
y_insert()  s/([aeiouAEIOU])([eiI])$/\1y\2/g
M_pattern_replace() s/M([kKgG])/f\1/g
                    s/M([cCjJ])/F\1/g
		    s/M([tTdD])/N\1/g
                    s/M([wWxX])/n\1/g
                    s/M([pPbB])/m\1/g
M_pattern_insert() calls replace() 	s/f([kKgG])/M\1/g
                    s/F([cCjJ])/M\1/g
                    s/N([tTdD])/M\1/g
                    s/n([wWxX])/M\1/g
								        		s/m([pPbB])/M\1/g
M_replace()									s/M/z/g
H_append()									s/$/H/g
a_replace()								s/([kctwpKCTWPgjdxbGJDXBfFNnmyrlvsSRh])a$/\1/g
M_rep_z_end()								s/iyAM$/iyAz/
Q_replace()									s/Q/q/g
*/

/**
 * FILE NAME : get_spell_variation.c 
 */

/** Function:  get_spellvariation
 *  This function is used for identifying the second letter of Hindi alphabets.
 *  Removes or replaces with the small letter in the input word.
 *  Arguments:orig of char array,words of 2 dimensional array ,
 *  word_count of int type and return type is char type
 * Return : char , return morph word after spel variation is done
 */ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern char *log_messg;

#define FUNCTION "get_spell_variation()"

#define RULE 10
#define LEN 100
#define BIGGER_LEN 300

int Z_replace(char orig[LEN],char words[RULE][LEN],int word_count)
                                          /*removes Z in the input word*/                                                 
{
	int loop1,loop2;
	char *str_Z;

	str_Z=(char *)malloc((strlen(orig)+1)*sizeof(char));
	sprintf(log_messg, "INFO: going check word contains Z=|%s|", str_Z); PRINT_LOG(log_file,log_messg);
	
	for(loop1=0,loop2=0;loop1<strlen(orig);loop1++,loop2++)
		{
		if(orig[loop1]=='Z')
			loop2--;
		else
			str_Z[loop2]=orig[loop1];
		}
	str_Z[loop2]='\0';
	
	if(strcmp(orig,str_Z)!=0)
		strcpy(words[word_count++],str_Z);
	sprintf(log_messg, "INFO: word  contains Z and it is replaced with NULLi |%s|", str_Z); PRINT_LOG(log_file,log_messg);
	free(str_Z);
	return word_count;   /*returns the word size after replacing*/
}


int  M_replace(char orig[LEN],char words[RULE][LEN],int word_count)
                         /*removes M and places z  in the input word*/
{
	int loop1,loop2;
	char *str_M;

	str_M=(char *)malloc((strlen(orig)+1)*sizeof(char));
	
	for(loop1=0,loop2=0;loop1<strlen(orig);loop1++,loop2++)
		{
		if(orig[loop1]=='M')
			str_M[loop2]='z';
		else
			str_M[loop2]=orig[loop1];
		}
	str_M[loop2]='\0';
	
	if(strcmp(orig,str_M)!=0)
		//strcpy(words[word_count++],str_M);
		strcpy(words[word_count++],str_M);
	free(str_M);
	return word_count;/*returns the word size after replacing*/
}

int Q_replace(char orig[LEN],char words[RULE][LEN],int word_count)
                                    /*removes Q and places q in the input word*/
{
	int loop1,loop2;
	char *str_Q;

	str_Q=(char *)malloc((strlen(orig)+1)*sizeof(char));
	
	for(loop1=0,loop2=0;loop1<strlen(orig);loop1++,loop2++)
		{
		if(orig[loop1]=='Q')
			str_Q[loop2]='q';
		else
			str_Q[loop2]=orig[loop1];
		}
	str_Q[loop2]='\0';
	
	if(strcmp(orig,str_Q)!=0)
		strcpy(words[word_count++],str_Q);
	free(str_Q);
	return word_count;
}

 int  H_append(char orig[LEN],char words[RULE][LEN],int word_count) 
                                                 /*removes H in the input word*/
{	
strcpy(words[word_count],orig);
	words[word_count][strlen(orig)]='H';
	words[word_count++][strlen(orig)+1]='\0';
	return word_count; /*returns the word size after replacing*/
}

int a_replace(char orig[LEN],char words[RULE][LEN],int word_count)
{
	char *str_a,*check,ch;

	str_a=(char *)malloc((strlen(orig)+1)*sizeof(char));
	strcpy(str_a,orig);

	if(strlen(orig)>=2 && str_a[strlen(orig)-1]=='a') 
		{
		ch=str_a[strlen(orig)-2];
		check=index("kctwpKCTWPgjdxbGJDXBfFNnmyrlvsSRh",ch);
		if(check!=NULL)
			{
			str_a[strlen(orig)-1]='\0';
			strcpy(words[word_count++],str_a);
			}
		}
	free(str_a);
	return word_count;
}

int y_insert(char orig[LEN],char words[RULE][LEN],int word_count)
{
	char *str_y,*check,ch;

	str_y=(char *)malloc((strlen(orig)+2)*sizeof(char));
	strcpy(str_y,orig);

	if(strlen(orig)>=2)
		{
		ch=str_y[strlen(orig)-2];
		check=index("aeiouAEIOU",ch);
		if(check!=NULL)
			{
			ch=str_y[strlen(orig)-1];
			check=index("eiI",ch);
			if(check!=NULL)
				{
				str_y[strlen(orig)-1]='y';
				str_y[strlen(orig)]=ch;
				str_y[strlen(orig)+1]='\0';
				strcpy(words[word_count++],str_y);
				}
			}
		}
	free(str_y);
	return word_count;  /*returns the word size after replacing*/
}

int M_rep_z(char orig[LEN],char words[RULE][LEN],int word_count)

{
	int loop1;
	char *str_M_rep_z,*check,ch;
	
	str_M_rep_z=(char *)malloc((strlen(orig)+1)*sizeof(char));
	strcpy(str_M_rep_z,orig);
	
	for(loop1=0;loop1<strlen(orig);loop1++)
		{
		if(str_M_rep_z[loop1]=='M' && loop1!=0 )
			{
			ch=str_M_rep_z[loop1-1];
			if((check=index("EeoOiI",ch))==NULL)
				continue;
			else
				str_M_rep_z[loop1]='z';
			}
		}
		
	if(strcmp(orig,str_M_rep_z)!=0)
		strcpy(words[word_count++],str_M_rep_z);
	free(str_M_rep_z);
	return word_count;
}
			
int M_rep_z_end(char orig[LEN],char words[RULE][LEN],int word_count)
{
	char *str_M_rep_z,*check;
	
	str_M_rep_z=(char *)malloc((strlen(orig)+1)*sizeof(char));
	strcpy(str_M_rep_z,orig);
	
	if(strlen(orig)>=4)
		{
		check=&str_M_rep_z[strlen(orig)-4];
		if(strstr(check,"iyAM")!=NULL)
			str_M_rep_z[strlen(orig)-1]='z';
		}
		
	if(strcmp(orig,str_M_rep_z)!=0)
		strcpy(words[word_count++],str_M_rep_z);
	free(str_M_rep_z);
	return word_count; /*returns the word size after replacing*/
}
		
int M_pattern_replace(char orig[LEN],char words[RULE][LEN],int word_count)
{
	int loop1;
	char *str_rep_M,*check,ch;
	
	str_rep_M=(char *)malloc((strlen(orig)+1)*sizeof(char));
	strcpy(str_rep_M,orig);
	
	for(loop1=0;loop1<strlen(orig);loop1++)
		{
		if(str_rep_M[loop1]=='M')
			{
			if((ch=str_rep_M[loop1 + 1])=='\0')
				break;
			else if((check=index("kKgGcCjJtTdDwWxXpPbB",ch))==NULL)
				continue;
			else if((check=index("kKgG",ch))!=NULL)
				str_rep_M[loop1]='f';
			else if((check=index("cCjJ",ch))!=NULL)
				str_rep_M[loop1]='F';
			else if((check=index("tTdD",ch))!=NULL)
				str_rep_M[loop1]='N';
			else if((check=index("wWxx",ch))!=NULL)
				str_rep_M[loop1]='n';
			else if((check=index("pPbB",ch))!=NULL)
				str_rep_M[loop1]='m';
			}
		}
		
	if(strcmp(orig,str_rep_M)!=0)
		strcpy(words[word_count++],str_rep_M);
	free(str_rep_M);
	return word_count;  /*returns the word size after replacing*/
}

void replace(char *str_ins_M,char ch,char *pat)
{
	int loop1;
	char *check,letter;

	for(loop1=0;loop1<strlen(str_ins_M);loop1++)
		{
		if(str_ins_M[loop1]==ch)
			{
			if((letter=str_ins_M[loop1+1])=='\0')
				break;
			else if((check=index(pat,letter))==NULL)
				continue;
			else
				str_ins_M[loop1]='M';
			}
		}
}

int M_pattern_insert(char orig[LEN],char words[RULE][LEN],int word_count)
{
	//int loop1;
	char *str_ins_M;
	
	str_ins_M=(char *)malloc((strlen(orig)+1)*sizeof(char));
	strcpy(str_ins_M,orig);
	
	replace(str_ins_M,'f',"kKgG");
	replace(str_ins_M,'F',"cCjJ");
	replace(str_ins_M,'N',"tTdD");
	replace(str_ins_M,'n',"wWxX");
	replace(str_ins_M,'m',"pPbB");

	if(strcmp(orig,str_ins_M)!=0)
		strcpy(words[word_count++],str_ins_M);
	free(str_ins_M);
	return word_count;  /*returns the word size after replacing*/
}

extern void fun_morph();
void get_spell_variation(orig,words,word_count)
char orig[LEN];
char words[RULE][LEN];
int word_count;
{
	int loop1,loop2; //,test_eof;
	char sort[RULE]; //,morph_path[LEN],cmd[BIGGER_LEN],cmd1[BIGGER_LEN];
	//FILE *file,*file_orig;
        PRINT_LOG(log_file, "This is get_spell_variation()\n");
	
	 word_count=0;
	
	word_count=Z_replace(orig,words,word_count);
	word_count=M_rep_z(orig,words,word_count);
	word_count=y_insert(orig,words,word_count);
	word_count=M_pattern_replace(orig,words,word_count);
	word_count=M_pattern_insert(orig,words,word_count);
	word_count=M_replace(orig,words,word_count);
	word_count=H_append(orig,words,word_count);
	word_count=a_replace(orig,words,word_count);
	word_count=M_rep_z_end(orig,words,word_count);
	word_count=Q_replace(orig,words,word_count);
	
	/* for sorting uniquely the words and writing it to the file */
	for(loop1=0;loop1<word_count;loop1++)
		sort[loop1]='U';
	
	for(loop1=0;loop1<word_count-1;loop1++)
		{
		if(sort[loop1]!='U')
			continue;
		for(loop2=loop1+1;loop2<word_count;loop2++)
			{
			if(!strcmp(words[loop1],words[loop2]))
				sort[loop2]='D';
			}
		}
		
/*	file=fopen("TMP","a");
	file_orig=fopen("TMP.orig","a");
	for(loop1=0;loop1<word_count;loop1++)
		{
		if(sort[loop1]=='U')
			{
			fprintf(file,"%s\n",words[loop1]);
			fprintf(file_orig,"%s\n",orig);
			}
		}
	fclose(file);
	fclose(file_orig); */

//return (words);  /*returns the word after Spell variaton is performed*/
}
