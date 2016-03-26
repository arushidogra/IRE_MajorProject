/**
  * File Name : main.c
  */



/** Function : main
  * This function is the main function where we take input word and actual flow of each function
  * from begining to ending is defined here
  * It takes arguments: argv of char type and argc of integer type
  * Return : int, 
  */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <fcntl.h>
#include <gdbm.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <ctype.h>

extern void my_fatal ();

#include "struct1.h"
#include "glbl.h"
#include "defn.h"
#include "struct.h"
#include "morph_logger.h"
#include "c_api_v2/c_api_v2.h"

/* Global Variables */
int DEBUG;
int DEBUG_NEW;
int FINDONCE;
int FOR_USER;			/* for user friendly output */
int DEFAULT_PARADIGM;		/* for choosing default paradigm if it is not
				   present in the dict */
int ALWAYS_DEFAULT_PARADIGM;	/*  always choose the default paradigm ,
				   even though entry is found in dict */

int TCP_SERVER_FLAG;            /* create a fork()-ing TCP server */
int TCP_SERVER_PORT;            /* port number for TCP Server to bind() on */

char *log_messg;	/*test var----*/

int WORD_NUM;			/* for assigning word number */
int SENT_NUM;			/*for assigning sentence number */
int LINE_NUM_FLAG;		/* checks for line number is there or not */
int UWORD_DICT;			/* checks for uword dict is there or not */
int HORI_OUTPUT;		/* checks for Horizontal output  */
int YES_NO;			/* answer yes if word is present in dict */
int INFLTNL;
int sizeof_prop_noun_lex;	/* size of proper noun lexical information */
struct lex_info prop_noun_lex_ar[Lexsize];	/* lexical information structure */

char *program_name = "main";
char *log_filepath;
char *message;
FILE *log_file;


 /**
  * Prototypes of the functions in this file with a file scope
  */
extern void fgetword ();
extern void fun_close ();
extern void chk_uword_dict ();
extern void resufun ();
extern void resufun_hori ();
extern void fun_morph ();
extern char fun_read ();
extern int snt_num ();
extern int end_mark ();
extern void print_snt_num ();
extern void get_spell_variation();
extern void prnt_spell_variation();
node *data_str;

#define FUNCTION "main()"

#define TCP_SERVER_MAX_QUEUE_LENGTH 256
#define TCP_SERVER_MAX_BUFFER_SIZE 10240

int
main (argc, argv)
     int argc;
     char *argv[];
{
  FILE *fpt1 = NULL;		/* File pointer for uword */
  FILE *fp_pdgm;		/* File pointer for pdgm_offset_info */
  FILE *fp_prop_noun_dict;	/* File pointer for prop_noun_lex.dic */
  FILE *fp_uword_dict;		/* File pointer for uword.dic */
  FILE *fp_excepword_dict;	/* File pointer for exception words */

  GDBM_FILE db_dict, db_suff, db_uword;	/* global dictionary objects */

  char morph[Morphsize];	/* morph word */
  /* filepath , filename ,filepath of dict */
  char fpath[BigArray], fname[BigArray], fpath_dict[BigArray];
  char upath[BigArray], uname[BigArray], ename[BigArray], lname[BigArray];	/* uword path, uword name */
  char line[SmallArray];
  int loop1, swit1, c, k, flag_uword, FLAG=0; //,first = 1, pipe_flag;
  struct ans_struct ans_ar[Arraysize];
  /* lexical info of word , ie word,rootword, pdgm,cat */
  char uword_ans[BigArray];	/* uword ans */
  char *pdm, *uword, *dict;	/*pdm for --pdgmfilepath argument , 
				   uword for --uwordpath argument,
				   dict for --dictfilepath argument */
  extern char *optarg;
  char *infile, *outfile, iname[BigArray], oname[BigArray];    /*morphinput and output option variables */
  extern FILE *stdin;
  extern FILE *stdout;

 //char root[BigArray], cat[BigArray], g[BigArray],
 //		n[BigArray], p[BigArray], kase[BigArray],
 //		cm[BigArray], tam[BigArray];

  int sizeof_uword;		/* size of uword */
  struct uword_dict uword_ar[Uwordlen];
  char morph_spell_variation[SmallArray][SmallArray];	/* morph word */
  int word_count = 0;		/* word count */
  //char w;
  char final_feature_struct[LargeArray];

/* intialising variables */
  swit1 = 1;
  DEBUG = 0;
  DEBUG_NEW = 0;
  FINDONCE = 0;
  FOR_USER = 0;
  DEFAULT_PARADIGM = 0;
  ALWAYS_DEFAULT_PARADIGM = 0;
  WORD_NUM = 0;
  SENT_NUM = 0;
  LINE_NUM_FLAG = 0;
  UWORD_DICT = 0;
  HORI_OUTPUT = 0;
  YES_NO = 0;
  INFLTNL = 1;
  TCP_SERVER_FLAG = 0;

  infile = NULL;
  outfile = NULL;
/* [ESC] increase size 1024 from 256 to handle segmentation fault issue if fs > 8  */
  log_messg = (char*) malloc(sizeof(char)*1024); 
  memset(log_messg, '\0', 1024);
	

  while (1) {
      static struct option long_options[] = {
	{"logfilepath", required_argument, 0, 'f'},
	{"pdgmfilepath", required_argument, 0, 'p'},
	{"uwordpath", required_argument, 0, 'u'},
	{"dictfilepath", required_argument, 0, 'd'},
	{"inputfile", required_argument, 0, 'i'},
	{"outputfile", required_argument, 0, 'o'},
        {"tcpserver", required_argument, 0, 'x'},
        {"help", no_argument, 0, 'h'},
	{0, 0, 0, 0}
      };
      int option_index = 0;

      k = getopt_long (argc, argv, "fpudioxhUFPADLHWGY",
		       long_options, &option_index);
      if (k == -1)
	break;
      switch (k) {
/* OPTION 'f' log file path */
	case 'f':
	  log_filepath = optarg;
	  strcpy (lname, log_filepath);
	  if ((log_file = fopen (lname, "w")) == NULL)
	    {
	      perror ("MORPH.log");
	    }
	  break;

/* OPTION 'p' pdgm path */
	case 'p':
	  pdm = optarg;
		strcpy (fpath, pdm); strcpy (fname, fpath); strcat (fname, "/pdgm_offset_info");
	  break;
/* OPTION 'u' for uword dict path */
	case 'u':
	  uword = optarg;
          break;
/* OPTION 'd' for dictpath */
	case 'd':
	  dict = optarg;
	  break;
/* OPTION 'U' creates a file uword which captures the words beyond the scope of the morph */
	case 'U':
	  swit1 = 0;
	  break;
        case 'x':
          TCP_SERVER_FLAG = 1;
          TCP_SERVER_PORT = atoi(optarg);
          break;
        case 'i':
          infile = optarg;
          strcpy (iname, infile);
          if ((stdin = fopen (iname, "r")) == NULL) {
              sprintf(log_messg, "ERROR: Could not open |%s| file\n", iname);
              PRINT_LOG (log_file, log_messg);
              exit (0);
          } else
              PRINT_LOG (log_file, "InputFile opened Sucessfully\n");
          break;
          /* OPTION o for output file */
        case 'o':
          outfile = optarg;
          strcpy (oname, outfile);
          if ((stdout = fopen (oname, "w")) == NULL) {
              sprintf(log_messg, "ERROR: Could not open |%s| file\n", oname); PRINT_LOG (log_file, log_messg);
              exit (0);
          } else
              PRINT_LOG (log_file, "OutputFile opened Sucessfully\n");
          break;
/* OPTION 'F' is used for user friendly output */
	case 'F':
	  FOR_USER = 1;
	  break;
/* OPTION 'P' choose the default paradigm , if entry is not found in dict */
	case 'P':
	  DEFAULT_PARADIGM = 1;
	  break;
/* OPTION 'A' always choose the default paradigm ,even though entry is found in dict */
	case 'A':
	  ALWAYS_DEFAULT_PARADIGM = 1;
	  break;
/* OPTION 'D' dbm files are being used */
	case 'D':
	  DBM_FLAG = 1;
	  break;
/* OPTION 'L' line numbers are being provided by some other program */
	case 'L':
	  LINE_NUM_FLAG = 1;
	  break;
	case 'H':
	  HORI_OUTPUT = 1;
	  break;
/* OPTION 'W' check the Uword dict */
	case 'W':
	  UWORD_DICT = 1;
	  break;
	case 'G':
	  DEBUG = 1;
	  break;
/* OPTION 'Y' answers yes if morph recognises, else answers no */
	case 'Y':
	  YES_NO = 1;
	  break;
        case 'h':
	default:
	  printf("*****USAGE*****\n"
                 "--pdgmpath <pdgm_offset_info> --uwordpath <uword_dict_path> "
                 "--dictpath <dict_path> --logfilepath <path of the log file> "
                 "-ULDWH "
                 "--inputfile <input_file_path> --outputfile <output_file_path> | --tcpserver <port_number>\n");
	  exit (0);

	  break;
	}
    }

  if (!TCP_SERVER_FLAG && (!infile || !outfile)) {
      printf("Please specify either inputfile and outputfile or tcpserver\n");
      exit(-1);
  }

  if (infile && outfile) {
      sprintf(log_messg, "INFO: Entering Aplication with inputfile=%s, outputfile=%s", iname, outfile); PRINT_LOG (log_file, log_messg);
  }


  if (argc > 4)			/* argument is less than 3 */
    DEBUG_NEW = argv[4][0] - '0';
/*kittu  if (swit1 == 0)
    {
      if ((fpt1 = fopen ("uword", "w")) == NULL)
	{

	sprintf(log_messg, "ERROR: Could not open uword file |%s| please specify the correct path\n"); PRINT_LOG(log_file, log_messg);
	  exit (-1);
	}
    }
  else {
		sprintf(log_messg, "INFO: Uword file opened successfully"); PRINT_LOG(log_file, log_messg);
	}	 uword contains words which are beyond the scope of the morph  */



  strcpy (fpath, pdm);
  strcpy (fpath_dict, uword);
  strcpy (upath, dict);
  strcpy (fname, fpath);
  strcat (fname, "/pdgm_offset_info");
  /* check for pdgm file is not readable or not */
  if ((fp_pdgm = fopen (fname, "r")) == NULL)
    {
      fprintf (log_file,
	       "ERROR in opening pdgm_offset_info file %s please specify the correct path\n",
	       fname);

      exit (0);
    }
  else
    PRINT_LOG (log_file, " pdgm_offset_info file opened Sucessfully\n");

  strcpy (uname, upath);
  strcpy (ename, upath); // for exception words
  // [ESC] --- Need to change this hard coded resource for multiple instance to run.
  strcat (uname, "/prop_noun_lex.dic");
  strcat (ename, "/exception_words.txt"); // for exception words
  if ((fp_prop_noun_dict = fopen (uname, "r")) == NULL)	/* check for dict
							   is readable or not */
    {
      fprintf (log_file,
	       "ERROR in opening prop_noun_lex.dic file %s please specify the correct path\n",
	       uname);

      exit (0);
    }
  else
    PRINT_LOG (log_file, " prop_noun_lex.dic file opened Sucessfully\n");

  loop1 = 0;
  /* This function fetches the next wordfrom the current line of the specified file. */
  fgetword (fp_prop_noun_dict, line, ',');
  while (strcmp (line, ""))	/* comparing line with " " */
    {
      strcpy (prop_noun_lex_ar[loop1].word, line);
      /* This function fetches the next word from the current line of 
         the specified file. */
      fgetword (fp_prop_noun_dict, line, ',');
      strcpy (prop_noun_lex_ar[loop1].pdgm, line);
      /* This function fetches the next word from the current line of the specified file. */
      fgetword (fp_prop_noun_dict, line, ',');
      strcpy (prop_noun_lex_ar[loop1].cat, line);
      /* This function fetches the next word from the current line of the specified file. */
      fgetword (fp_prop_noun_dict, line, ',');
      loop1++;
    }
	sprintf(log_messg, "INFO: Added Proper Nouns into prop_noun_lex.dic, loop1 =%d", loop1); PRINT_LOG(log_file, log_messg);
  sizeof_prop_noun_lex = loop1;
  strcpy (uname, upath);
  // [ESC] --- Need to change this hard coded resource for multiple instance to run.
  strcat (uname, "/uword.dic");

/* check for uword dict is readable or not */
  if ((fp_uword_dict = fopen (uname, "r")) == NULL)
    {

      fprintf (log_file,
	       "ERROR in opening uword.dic file %s please specify the correct path\n",
	       uname);

      exit (0);
    }
  else

    PRINT_LOG (log_file, " uwrod.dic file opened Sucessfully\n");

  loop1 = 0;
  /* This function fetches the next word from the current line of the specified file. */
  fgetword (fp_uword_dict, line, ' ');
  while (strcmp (line, ""))	/* compares line with " " */
    {
      strcpy (uword_ar[loop1].sl_word, line);
      /* This function fetches the next word from the current line of the specified file. */
      fgetword (fp_uword_dict, line, '\n');
      strcpy (uword_ar[loop1].tl_word, line);
/* This function fetches the next word from the current line of the specified file. */
      fgetword (fp_uword_dict, line, ' ');
      loop1++;
    }
	sprintf(log_messg, "INFO: Added Uword into uword.dic, loop1=%d", loop1); PRINT_LOG(log_file, log_messg);
  sizeof_uword = loop1;
  if (DBM_FLAG != 1)		/* DBM_FLAG is not equal old dicts */
    {
      PRINT_LOG (log_file,
		 "\tCurrent version supports only dbm files for dictionaries. \
                        Plesae run with 'D' option\n Exiting ...\n");

      exit (1);
    }
  if (DBM_FLAG)			/* if DBM_FLAG is true */
    {
      strcpy (fname, fpath_dict);
      /* my_fatal: This function displays a message  "File not found"
         when the files dict_final,suff are not there */
      db_dict = gdbm_open (fname, 512, GDBM_READER, 0666, my_fatal);
      strcpy (fname, fpath);
      strcat (fname, "/suff");
      /* my_fatal: This function displays a message  "File not found"
         when the files dict_final,suff are not there */
      db_suff = gdbm_open (fname, 512, GDBM_READER, 0666, my_fatal);
      strcpy (fname, fpath);
      strcat (fname, "/uword.dbm");
      /* my_fatal: This function displays a message  "File not found"
         when the files dict_final,suff are not there */
      db_uword = gdbm_open (fname, 512, GDBM_READER, 0666, my_fatal);
    }
  SENT_NUM++;
  if (LINE_NUM_FLAG == 0)	/* check for LINE_NUM_FLAG is 0 */
    if ((!HORI_OUTPUT) && !YES_NO)	/* HORI_OUTPUT AND YES_NO are not true */
      printf ("# s%d/n", SENT_NUM);
	sprintf(log_messg, "INFO: Opened GDBM database files needed to run morph"); PRINT_LOG(log_file, log_messg);

    int listenfd,connfd,morph_in_size, morph_out_size;
    struct sockaddr_in servaddr,cliaddr;
    char mesg[TCP_SERVER_MAX_BUFFER_SIZE];
    char tmp_name[SmallArray] = "/tmp/fileXXXXXX";
    int fd;
    socklen_t clilen;
    pid_t childpid = 0;
    if (TCP_SERVER_FLAG) {
        listenfd=socket(AF_INET,SOCK_STREAM,0);

        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(TCP_SERVER_PORT);
        if (bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) == -1) {
            perror("bind");
            exit(-1);
        }

        /* Don't care what the child returns */
        signal(SIGCHLD, SIG_IGN);

        if (listen(listenfd, TCP_SERVER_MAX_QUEUE_LENGTH) == -1) {
            perror("listen");
            exit(errno);
        }
    }
    for (;;) {
        if (TCP_SERVER_FLAG) {
            clilen=sizeof(cliaddr);
            connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
            if (connfd < 0) {
                perror("accept");
                exit(errno);
            }
            childpid = fork();
            if (childpid < 0) {
                perror("fork");
                exit(-1);
            }
        }
        if (childpid == 0) { /* Either inside child() or when !TCP_SERVER_FLAG */
            if(TCP_SERVER_FLAG) {
                close (listenfd);

                morph_in_size = recvfrom(connfd, mesg, TCP_SERVER_MAX_BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &clilen);

                fd = mkstemp(tmp_name);
                write(fd, mesg, morph_in_size);
                close(fd);

                sprintf(fname, "%s/pdgm_offset_info", fpath);
                /* each child should've it's own FILE * to avoid race conditions */
                if (!(fp_pdgm = fopen (fname, "r"))) {
                    exit (errno);
                }
            }
            //sprintf(log_messg, "Going to read input file |%s| using SSF API", iname); PRINT_LOG(log_file, log_messg);
            data_str = create_tree ();
            sprintf(log_messg, "INFO: SSF Input File is |%s|", iname); PRINT_LOG(log_file, log_messg);
            read_ssf_from_file(data_str, TCP_SERVER_FLAG ? tmp_name : iname);
            sprintf(log_messg, "INFO: Child count is |%d|", data_str->child_count); PRINT_LOG(log_file, log_messg);

            int var;
            for (var = 0; var < data_str->child_count; var++) {
                char feature_str[BiggerArray];
                feature_str[0] = '\0';
                // [ESC] --- no check for return from function
                node *child = get_nth_child (data_str, var);

                /* this function reads the input word */
                sprintf(log_messg, "INFO: Going to call fun_read()"); PRINT_LOG(log_file, log_messg);
                c = fun_read(morph, get_field(child, 1));
                sprintf(log_messg, "INFO: Returned from fun_read(), c = |%d| count=%d|word=%s|\n", c, var, morph); PRINT_LOG(log_file, log_messg);

                /* fun_read() is buggy. Copy the input word to morph anyway */
                strcpy(morph, get_field(child, 1));

                /* checks for morph is null or not */
                if (strcmp(morph, "\0"))	{
                    sprintf(log_messg, "INFO: Input word is |%s|", morph); PRINT_LOG(log_file, log_messg);
                    FINDONCE = 0;
                    /* checks fo r line no. , snt no., and o/p are there or not */
                    if ((LINE_NUM_FLAG && snt_num (morph)) && (!HORI_OUTPUT)
                        && (!YES_NO))
                        /* snt_num() This function marks a sentence number to the word */
                        print_snt_num (morph);
                    else		/* checks fo r line no. , snt no., and o/p are there  */
                    {
                        WORD_NUM++;
                        if (FOR_USER && !HORI_OUTPUT)	/* o/p is not there */
                            printf ("@input_word@\n word_num: w%d\n", WORD_NUM);
                        else
                            /* if answer is not there and hori_output is not there */
                            if (!HORI_OUTPUT && !YES_NO)
                                printf ("input_word\nw%d\n", WORD_NUM);
                        if ((morph[0] == '@') || (LINE_NUM_FLAG && end_mark (morph)))	/* morph= @ */
                        {
                            if (!HORI_OUTPUT)	/*checks for output not there */
                                printf ("AVY\n%s\n", morph);	/* print the marked words as they are */
                            else
                                printf ("%s", morph);	/* print the marked words as they are */
                        }
                        else
                        {
                            /* This function checks the Unkown word is present in the UDictionary or not */
                            chk_uword_dict(morph, uword_ar->sl_word, sizeof_uword,
                                           sizeof (uword_ar[0]), strcmp,
                                           uword_ans, DBM_FLAG, db_uword);
                            /* checks for uword not null and uword_dict is there */
                            if ((uword_ans[0] != '\0') && (UWORD_DICT))
                                if (!HORI_OUTPUT && !YES_NO)	/* checks output and answer not there */
                                    printf ("AVY\n%s\n", uword_ans);
                                else if (YES_NO)	/* if answer is there */
                                    printf ("%s", morph);
                                else	/* if answer is not there */
                                    printf ("%s", uword_ans);
                            else
                            {
                                /* This function is the main functuon. It extracts suffixes and calls different routines for
                                   analysis */
                                sprintf(log_messg, "INFO: Calling fun_morph() for the word |%s|", morph); PRINT_LOG(log_file, log_messg);
                                fun_morph (morph, swit1, fpt1, fp_pdgm, DBM_FLAG, db_dict, db_suff, ans_ar);
                                loop1=0;
                                //[ESC] This is creating segmentation fault on big files
                                //sprintf(log_messg, "INFO: fun_morph() returned |%d|%s|%d|%s|", loop1, ans_ar[loop1].root, ans_ar[var].offset, ans_ar[var].pdgm); PRINT_LOG(log_file, log_messg);

                                /* if offest is equal to -2 for UNKNOWN Word*/
                                if (ans_ar[0].offset == -2)	{
                                    if (YES_NO)	/* checks for ajFAwa */
                                        printf ("%s<ajFAwa>", morph);
                                    get_spell_variation(morph,morph_spell_variation,word_count);
                                    flag_uword=1;
                                    for(loop1=0;loop1<=word_count;loop1++) {
                                        fun_morph(morph_spell_variation[loop1],swit1,fpt1,fp_pdgm,
                                                  DBM_FLAG,db_dict,db_suff,ans_ar);
                                        prnt_spell_variation(YES_NO, HORI_OUTPUT, morph, morph_spell_variation[loop1],ans_ar,
                                                             feature_str);
                                        if(ans_ar[0].offset != -2) {
                                            flag_uword=0;
                                        }
                                    }
                                    sprintf(final_feature_struct, "%s", feature_str);

                                    if ((swit1 == 0) && (flag_uword))
                                    {

                                        if ((fp_excepword_dict = fopen (ename, "r")) == NULL)    {
                                            sprintf(log_messg, "ERROR in opening exception_words file |%s| please specify the correct path", ename);
                                            PRINT_ERR(log_file, log_messg);
                                            exit (errno);
                                        } else {
                                            sprintf(log_messg, "exception_words file |%s| opened Sucessfully", ename);
                                            PRINT_LOG(log_file, log_messg);
                                        }

                                        fgetword(fp_excepword_dict,line,':');
                                        while (strcmp (line, ""))       /* compares line with " " */
                                        {
                                            FLAG=0;
                                            if(strcmp(line,morph)==0)
                                            {
                                                fgetword(fp_excepword_dict,line,':');
                                                sprintf(final_feature_struct, "<fs %s>", line);
                                                FLAG=1;
                                                break;
                                            }
                                            else
                                                fgetword(fp_excepword_dict,line,':');
                                            fgetword(fp_excepword_dict,line,':');
                                        }
                                        if(FLAG==0)
                                            sprintf(final_feature_struct, "<fs af='%s,unk,,,,,,'>", morph);
                                    }
                                }

                                else	/* checks for morph is there */
                                {
                                    if (YES_NO)	/* checks for answer is true */
                                        printf ("%s", morph);
                                    else	/* if answer is not there */
                                    {
                                        loop1 = 0;
                                        /* checks for offset is not eual to -2 */
                                        while (ans_ar[loop1].offset != -2) {
                                            sprintf(log_messg, "INFO: Reading Analysis for word |%s|, analysis#=%d", ans_ar[loop1].root, loop1); PRINT_LOG(log_file, log_messg);

                                            if (ans_ar[loop1].offset == -1) {	/* checks for offset is not eual to -1 */
                                                if (!HORI_OUTPUT) {	/* if output not there */
                                                    printf ("avy\n%s\n", ans_ar[loop1].root);
                                                    sprintf(feature_str, "<fs af='%s,avy,,,,,,'>", ans_ar[loop1].root);
                                                } else {
                                                    printf ("%s{avy}", ans_ar[loop1].root);
                                                    sprintf(feature_str, "<fs af='%s,avy,,,,,,'>", ans_ar[loop1].root);
                                                }
                                            } else if (ans_ar[loop1].offset == -3) {	/* Case of Numeral */
                                                if (!HORI_OUTPUT) {	/* if output not there */
                                                    printf ("avy\n%s\n", ans_ar[loop1].root);
                                                } else {	/* if answer is there */
                                                    sprintf(log_messg, "INFO: NUMERALS, SPECIAL, & PUNCTUATIONS |%s|", ans_ar[loop1].root); PRINT_LOG(log_file, log_messg);

                                                    if (ispunct(ans_ar[loop1].root[0])) {
                                                        if(ans_ar[loop1].root[0]==',')
                                                            sprintf(feature_str, "<fs af='&comma,punc,,,,,,'>");
                                                        else if(ans_ar[loop1].root[0]=='/')
                                                            sprintf(feature_str, "<fs af='&slash,punc,,,,,,'>");
                                                        else
                                                            sprintf(feature_str, "<fs af='%c,punc,,,,,,'>", ans_ar[loop1].root[0]);
                                                    } else {
                                                        sprintf(feature_str, "<fs af='%s,num,,,,,,'>", ans_ar[loop1].root);
                                                    }
                                                    sprintf(log_messg, "INFO: NUMERALS, SPECIAL, & PUNCTUATIONS |%s|", ans_ar[loop1].root); PRINT_LOG(log_file, log_messg);
                                                }
                                            } else if (HORI_OUTPUT) {
                                                /* This function prints the output in horizontal way for the given input word */
                                                char root[BigArray],
                                                     cat[BigArray], g[BigArray],
                                                     n[BigArray], p[BigArray],
                                                     kase[BigArray],
                                                     cm[BigArray], tam[BigArray],p_tem[BigArray],emph[SmallArray],gen1[BigArray],num1[BigArray],cas1[SmallArray];

                                                sprintf(log_messg, "INFO: Calling resufun_hori(),|root=%s|cat=%s|gender=%s|number=%s|person=%s|case=%s|cm=%s|suff=%s|", root, cat, g, n, p, kase, cm, tam); PRINT_LOG(log_file, log_messg);

                                                /* Initalize the variables so that they donot carry the last values*/
                                                memset(g, '\0', sizeof(g));
                                                memset(n, '\0', sizeof(n));
                                                memset(p, '\0', sizeof(p));
                                                memset(kase, '\0', sizeof(kase));
                                                memset(cm, '\0', sizeof(cm));
                                                memset(tam, '\0', sizeof(tam));
                                                memset(emph, '\0', sizeof(emph));
                                                memset(gen1, '\0', sizeof(gen1));
                                                memset(num1, '\0', sizeof(num1));
                                                memset(cas1, '\0', sizeof(cas1));

                                                resufun_hori(ans_ar[loop1].root,
                                                             ans_ar[loop1].pdgm,
                                                             ans_ar[loop1].offset,
                                                             ans_ar[loop1].aux_verb,
                                                             root, cat, g, n, p, kase, cm,
                                                             tam, emph, gen1, num1, cas1);

                                                //sprintf(log_messg, "INFO: resfun_hori returns|root=%s|cat=%s|gender=%s|number=%s|person=%s|case=%s|cm=%s|suff=%s|emph=%s|gen1=%s|num1=%s|cas1=%s", root, cat, g, n, p, kase, cm, tam, emph, gen1, num1, cas1); PRINT_LOG(log_file, log_messg);

                                                if(!strcmp(cat,"sh_P")){
                                                    memset(cat, '\0', sizeof(cat));
                                                    strcat(cat,"pn");
                                                }
                                                else if(!strcmp(cat,"sh_n")){
                                                    memset(cat, '\0', sizeof(cat));
                                                    strcat(cat,"psp");
                                                }
                                                if(!strcmp(cat,"n")) {
                                                    if(!strcmp(p,"")){
                                                        strcpy(p,"3");
                                                    }
                                                }


                                                //This block of code is introduced to make separate key value pair for the honorophic cases and '2h','3h' are not valid values for the person so that they are converted into '2' and '3' correspondingly
                                                if( (!strcmp(p,"2h") || (!strcmp(p,"3h"))) && ((!strcmp(gen1,"m"))||(!strcmp(gen1,"f")) )) {
                                                    p_tem[0]=p[0];p_tem[1]='\0';
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' agr_gen=\'%s\' agr_num=\'%s\' agr_cas=\'%s\' hon=\'y\'>", root, cat, g, n, p_tem, kase, cm, tam, gen1, num1,cas1);
                                                }
                                                else if( (!strcmp(p,"2h") || (!strcmp(p,"3h"))) && ((!strcmp(emph,"y")) )) {
                                                    p_tem[0]=p[0];p_tem[1]='\0';
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' emph=\'%s\' hon=\'y\'>", root, cat, g, n, p_tem, kase, cm, tam, emph);
                                                }
                                                else if(!strcmp(p,"2h") || !strcmp(p,"3h")){
                                                    p_tem[0]=p[0];p_tem[1]='\0';
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' hon='y'>", root, cat, g, n, p_tem, kase, cm, tam);
                                                }
                                                else if( (!strcmp(emph,"y")) && ((!strcmp(gen1,"m"))||(!strcmp(gen1,"f")) )) {
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' emph=\'%s\' agr_gen=\'%s\' agr_num=\'%s\' agr_cas=\'%s\'>", root, cat, g, n, p, kase, cm, tam, emph, gen1, num1,cas1);
                                                }
                                                else if( (!strcmp(gen1,"m"))||(!strcmp(gen1,"f")) ) {
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' agr_gen=\'%s\' agr_num=\'%s\' agr_cas=\'%s\'>", root, cat, g, n, p, kase, cm, tam, gen1, num1, cas1);
                                                }
                                                else if(!strcmp(emph,"y")) {
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' emph=\'%s\'>", root, cat, g, n, p, kase, cm, tam, emph);
                                                }
                                                else {
                                                    sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s'>", root, cat, g, n, p, kase, cm, tam);
                                                }

                                                /*if(!strcmp(gen1,"m") || !strcmp(gen1,"f") ) {
                                                  sprintf(feature_str, "<fs af='%s,%s,%s,%s,%s,%s,%s,%s' gen1=\'%s\' num1=\'%s\'>", root, cat, g, n, p, kase, cm, tam, gen1,num1);
                                                  }*/


                                            }

                                            strcpy (ans_ar[loop1].root, "");
                                            ans_ar[loop1].offset = 0;
                                            strcpy (ans_ar[loop1].aux_verb, "");
                                            strcpy (ans_ar[loop1].pdgm, "");

                                            if (loop1 == 0) {
                                                sprintf(final_feature_struct, "%s", feature_str);
                                            } else {
                                                sprintf(final_feature_struct, "%s|%s", final_feature_struct, feature_str);
                                            }
                                            sprintf(log_messg, "lopp1 is |%d| and FS=%s", loop1, final_feature_struct); PRINT_LOG(log_file, log_messg);
                                            loop1++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((c == '.') || (c == '?'))	/* if for c is equal to '.' '?' */ {
                        WORD_NUM++;
                        if (!HORI_OUTPUT && !YES_NO)	/* This function prints the output in horizontal way for the given input word */
                            printf ("input_word\nw%d\nAVY\n%c\n", WORD_NUM, c);
                        else if (!YES_NO)
                            //	printf ("%c\n", c);
                            printf ("%s", "");
                        else
                            //	printf ("%c", c);
                            sprintf(final_feature_struct, "<fs af='%c,punc,,,,,,'>",c);
                        SENT_NUM++;
                        sprintf(final_feature_struct, "<fs af='%c,punc,,,,,,'>",c);

                    }

                }
                sprintf(log_messg, "INFO: Input word is null"); PRINT_LOG(log_file, log_messg);
                child->OR = read_or_node(final_feature_struct);
                sprintf(log_messg, "INFO: YOU ARE HERE"); PRINT_LOG(log_file, log_messg);
            } /*no more childs to process */

            //delete_node (get_nth_child(data_str, data_str->child_count - 1));
            //print_tree (data_str);
            print_tree_to_file(data_str, TCP_SERVER_FLAG ? tmp_name : oname);
            //fun_close (fpt1, fp_pdgm, swit1, DBM_FLAG, db_dict, db_suff);
            fun_close (fp_pdgm, swit1, DBM_FLAG, db_dict, db_suff);
            //sprintf(log_messg, "INFO: OUT of for"); PRINT_LOG(log_file, log_messg);
            if (TCP_SERVER_FLAG) {
                fd = open(tmp_name, O_RDONLY);
                morph_out_size = read(fd, mesg, TCP_SERVER_MAX_BUFFER_SIZE);
                sendto(connfd,mesg,morph_out_size,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
                unlink(tmp_name);
                exit(0);
            }
            //sprintf(log_messg, "INFO: OUT of else"); PRINT_LOG(log_file, log_messg);
        }
        sprintf(log_messg, "INFO: END OF WHILE"); PRINT_LOG(log_file, log_messg);
        close(connfd);
        if (!TCP_SERVER_FLAG)
            break;
    }
    return 0;
}
