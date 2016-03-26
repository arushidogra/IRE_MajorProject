/**
 * FILE NAME:print_spell_variation.c
*/

/** Function: prnt_spell_variation
 *  This function is used for printing the words that are identifed by the function
 *  get_spell_variation in horizontal way.
 *  Arguments:morph_spell_variation of char array, ans_ar is object array of structure ans_struct
 *  Return : void 
 */

/* HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct1.h"
#include "defn.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern char *log_messg;

#define FUNCTION "prnt_spell_variation()"

/**
 * Prototypes of the functions in this file with a file scope
*/

extern void resufun();
extern void resufun_hori();

void prnt_spell_variation(YES_NO, HORI_OUTPUT, morph, morph_spell_variation, ans_ar, feature_str)
int YES_NO;			/* answer is present or not */
int HORI_OUTPUT;		/* horizontal output */
char morph[Morphsize];			/* input word */
char morph_spell_variation[SmallArray];	/* speel variant word */
struct ans_struct ans_ar[SmallArray];	/* object of structure ans_structr  which contains info
					   of root,aux_verb,offset, paradigm */
char feature_str[BiggerArray];
{

    int loop1; //, pipe_flag;
    PRINT_LOG(log_file, "This is prnt_spell_variation()\n");


    char root[BigArray] = {'\0'}, cat[BigArray] = {'\0'}, g[BigArray] = {'\0'}, n[BigArray] = {'\0'}, p[BigArray] = {'\0'};
    char kase[BigArray] = {'\0'}, cm[BigArray] = {'\0'}, tam[BigArray] = {'\0'}; 


    if (ans_ar[0].offset != -2)	{ /* checks for case ie direct or indirect */

	if (YES_NO)		/* if answer is there */
		   printf("%s", morph);

	else {			/* if answer is not there */

	    loop1 = 0;
	    while (ans_ar[loop1].offset != -2) {	/* checks for offset is not eual to -2 */
		if (ans_ar[loop1].offset == -1)	/* checks for offset is not eual to -1 */
		    if (!HORI_OUTPUT)	/* if output not there */
			printf("Avy\n%s\n", ans_ar[loop1].root);
		    else
			printf("%s{Avy}", ans_ar[loop1].root);
		else if (ans_ar[loop1].offset == -3)	/* Case of Numeral */
		    if (!HORI_OUTPUT)	/* if output not there */
			printf("Avy\n%s\n", ans_ar[loop1].root);
		    else	/* if answer is there */
			printf("%s", ans_ar[loop1].root);
		else if (HORI_OUTPUT) {
		    /* This function prints the output in horizontal way for the given input word */
		   //resufun_hori(ans_ar[loop1].root, ans_ar[loop1].pdgm, ans_ar[loop1].offset, ans_ar[loop1].aux_verb,);
			
			//char root[BigArray], cat[BigArray], g[BigArray], n[BigArray], p[BigArray];
			//char kase[BigArray], cm[BigArray], tam[BigArray]; 

			resufun_hori(ans_ar[loop1].root, ans_ar[loop1].pdgm, ans_ar[loop1].offset, ans_ar[loop1].aux_verb, root, cat, g, n, p, kase, cm, tam);
			sprintf(log_messg, "INFO: resfun_hori returns|%s|%s|%s|%s|%s|%s|%s|%s|", root, cat, g, n, p, kase, cm, tam); PRINT_LOG(log_file, log_messg);
			if (loop1 == 0) {
				sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s'>", root, cat, g, n, p, kase, cm, tam);
			} else {
				sprintf(feature_str, "%s|<fs af='%s,%s,%s,%s,%s,%s,%s,%s'>", feature_str, root, cat, g, n, p, kase, cm, tam);
			}

			}
		else
		    /* This function prints the root, pdgm,priority ,category */
		    resufun(ans_ar[loop1].root, ans_ar[loop1].pdgm,
			    ans_ar[loop1].offset, ans_ar[loop1].aux_verb);
		strcpy(ans_ar[loop1].root, "");
		ans_ar[loop1].offset = 0;
		strcpy(ans_ar[loop1].aux_verb, "");
		strcpy(ans_ar[loop1].pdgm, "");
		loop1++;
	    }
	}
    }
	sprintf (log_messg, "INFO: going out of print_spell_variation()"); PRINT_LOG(log_file,log_messg);
}
