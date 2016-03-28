#include <stdio.h>
#include <string.h>
#include "/1d1/mt/com/lwg/prog/headers/defn.h"

main()
{
	int i,j;
	char chr,cat_c;
	char flag[MAX_CHR_IN_PRATIPADIK],root_s[MAX_CHR_IN_PRATIPADIK];
	char root[MAX_CHR_IN_PRATIPADIK];
	char gender[GENDER],number[NUMBER],person[PERSON];
	char case_tmp[CASE_TMP],parsarg[MAX_CHR_IN_PARSARG];
	char tam[100];

	i=0;j=0;
	getline(flag);
        do
        {
	chr = 'a'; /* only initialization.to be modified */
	while(chr != '\0' && chr != '#'){
	getline(flag);
	     while(!strcmp(flag,"input_word"))
	     {
	     getline(flag);
	     while(strcmp(flag,"input_word") && (flag[0]!='\0') && (flag[0]!='#'))
	     {
	      cat_c=flag[0];
	      getline(root_s);
              printf("%s ",root_s);
	     switch (cat_c) {
	     case 'A': printf("\n");
			break;
	     case 'v':
	     	     getline(tam);
		     printf("%s ",tam);
		     getline(gender);
		     getline(number);
		     getline(person);
                     printf("[%s,%s,%s,%s]\n",flag,gender,number,person);
		     break;
	     case 'n':
		     getline(gender);
		     getline(number);
		     getline(case_tmp);
                     getline(parsarg);
                     printf("%s ",parsarg);
                     printf("[%s,%s,%s,%s]\n",flag,gender,number,case_tmp);
		     break;
	     case 'P':
		     getline(gender);
		     getline(number);
		     getline(case_tmp);
                     getline(parsarg);
                     printf("%s ",parsarg);
                     printf("[%s,%s,%s,%s]\n",flag,gender,number,case_tmp);
		     break;
	     }
	     getline(flag);
             j++;
             }
             i++;j=0;
             }
             chr=flag[0];
             }
	     } while (chr == '#');
     }
