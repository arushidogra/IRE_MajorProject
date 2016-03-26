/**
 * File Name :order_ssf.c
 */

/**
  * this file is required to order the output in SSF
  */


#include "struct.h"
struct order_ssf_info order[12]={
    {
        {
            "v",           /* for lexical category verb */
        },
        {
            "gender",      /* gender */
            "number",      /* number */
            "person",      /* person */
            "case",
            "cm",
            "tam",         /* suffix indicating Tense Aspect Modality */
        },
    },
    {
        {
            "vn",
        },
        {
            "gender",
            "number",
            "person",
            "case",
            "cm",
            "tam",
        },
    },
    {
        {
            "n"
        },       /*lexical category for noun */
        {
            "gender",  /* "gender"er */
            "number",  /* number */
            "person",  /* person */
            "case",	   /* case */
            "cm",
            "parsarg", /* parsarg */
        }
    },
    {
        {
            "pn",
        },
        {
            "gender",  /* "gender"er */
            "number",  /* number */
            "person",  /* person */
            "case",	   /* case */
            "cm",
            //"tam", /* parsarg */
            "parsarg",
            "emph", /* added by Rashid for emphatic pronoun*/
        }
    },
    {
        {
            "psp",
        },
        {
            "gender",  /* "gender"er */
            "number",  /* number */
            "person",  /* person */
            "case",	   /* case */
            "cm",
            //"tam", /* parsarg */
            "parsarg",
        },
    },
    {
        {
            "adj",        /* for Adjective */
        },
        {
            "gender",     /* "gender"er */
            "number",     /* number */
            "person",     /* person */
            "case",	      /* case */
            "cm",
            "tam",       /* complete suff */
            "emph", /* */
        },
    },
    {
        {
            "P",          /* lexical category pronoun*/
        },
        {
            "gender",     /* "gender */
            "number",     /* number */
            "person",     /* person */
            "case",	      /* case */
            "cm",
            //"tam",       /* complete suffix */
            "parsarg",
        },
    },
    {
        {
            "Avy",
        },
        {
            "gender",     /* "gender"er */
            "number",     /* number */
            "person",     /* person */
            "case",	      /* case */
            "cm",
            "tam",       /* complete suffix */
        },
    },
    {
        {
            "avy",
        },
        {
            "gender",     /* "gender"er */
            "number",     /* number */
            "person",     /* person */
            "case",	      /* case */
            "cm",
            "tam",       /* complete suffix */
        },
    },
    /* Added for Sanskrit, avy is better than Avy, Hint: view in devenagari */
    /* Afterwords delete Avy category, and also make changes in Ca Ce Fe files of other langauges. */
    {
        {
            "sh_n",
        },
        {
            "number",
            "gender",
            "number1",
            "case",
            "cm",
            "tam",
            "parsarg", /* parsarg */
        }
    },
    {
        {
            "adv",
        },
        {
            "gender",
            "number",
            "person",
            "case",
            "cm",
            "tam",
        },
    },
    {
        {
            "sh_P",
        },
        {
            "gender",
            "number",
            "person",
            "case",
            "cm",
            /*"tam",*/
            "parsarg", /* parsarg */
            "emph", /* */
            "gen1", /* */
            "num1",
            "cas1",
        }
    }
};
