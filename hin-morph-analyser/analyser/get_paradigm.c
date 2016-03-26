/**
 * File Name : get_paradigm.c
 */

/** Function:get_paradigm
 * This function takes the last letter of the word and checks the guessed paradigm from the 
 * paradigm list using the switch case
 * It takes arguments : word of char array and pdgm of char array
 * Return void 
 */



#include <string.h>
#include "defn.h"

void get_paradigm(word,pdgm)
  char word[WORD_SIZE];        /* morph word */
  char pdgm[WORD_SIZE];        /* paradigm */
  {
	int n;
	//struct exp_pdgm *tag;  /* guessed paradigm object of strucure exp_pdgm */
	pdgm[0]='\0';
	n = strlen(word);
   /* takes the last letter of the word and checks the guessed paradigm from the
        paradigm list using the switch case */
	switch(word[n-1])
	 {
           case 'a' : strcpy(pdgm,"Gara");
		   break;
	   case 'A' : strcpy(pdgm,"ladakA");
		   break;
	   case 'i' : strcpy(pdgm,"kavi");
	    	   break;
	   case 'I' : strcpy(pdgm,"ladakI");
	 	   break;
	   case 'u' : strcpy(pdgm,"Sawru");
		   break;
	   case 'U' : strcpy(pdgm,"AlU");
	 	   break;
	   case 'z' : strcpy(pdgm,"kuAz");
		   break;
	   case 'M' : strcpy(pdgm,"sarasoM");
		   break;
	   case 'o' : strcpy(pdgm,"redio");
		   break;
	  }
   }
