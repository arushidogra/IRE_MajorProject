/**
 * FILE NAME : verify_root.c
*/

/** Function : verify_root
 *  This function compares the guessed root , paradigm,category with the data in the dictionary
 *  It takes arguments: INFLTNL of int type,guessed_root of char array ,pdgm of char array,
 *  cat of char array ,offset of int type ,ans_table is object of lex_info structure
 *  ans_ar is object of the structure os ans_struct, j is integer file pointer
 *  DBM_FLAG is of int type and db is object of file dbm
 *  Return : void
 */


#include <stdio.h>
#include <string.h>
#include <gdbm.h>

/* HEADER FILES */
#include "defn.h"
#include "struct.h"
#include "struct1.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern int match_in_dict();

#define FUNCTION "verify_root()"

void test_hypothetical_dict(root,pdgm,cat,suff_offset,ans_ar,j,DBM_FLAG,db)
   /* root word, paradigm,category */
   char root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
   int suff_offset,*j;   /* suffix offset case */
   struct ans_struct ans_ar[Arraysize];   /* ans_struct structure object, this structure
                                           contains root,offset,auxilary verb and paradigm */
   int DBM_FLAG; 			     /* global dictionary flag */
   GDBM_FILE db;                         /* GNU database manager includes dbm and ndb                                                        compatability and db is used for opening file */
 {}

void verify_root(INFLTNL,guessed_root,pdgm,cat,offset,ans_table,ans_ar,j,DBM_FLAG,db)

  int INFLTNL;
  /* guessed root, paradigm, category */
  char guessed_root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
  int offset,*j;   /* offset for cases ie direct or indirect case */
  struct lex_info ans_table[SmallArray]; /* lexical structure object , structure contains 
                                          details of word , paradigm,category ,priority */
  struct ans_struct ans_ar[Arraysize];   /* ans_struct structure object, this structure contains
                                          root,offset,auxilary verb and paradigm */
  int DBM_FLAG;                          /*global dictionary flag */
  GDBM_FILE db;                          /* GNU database manager includes dbm and ndb 
                                            compatability and db is used for opening file */

    {
	int match1;                            /* matching root */
	/*This function compares the guessed root, pdgm,cat in the dictionary file */
        PRINT_LOG(log_file, "comparing the guessed root , paradigm,category with the data in the dictionary\n");
	match1 = match_in_dict(guessed_root,pdgm,cat,offset,ans_table,ans_ar,j);  
	if(!match1)
	   test_hypothetical_dict(guessed_root,pdgm,cat,offset,ans_ar,j,DBM_FLAG,db);
    }
