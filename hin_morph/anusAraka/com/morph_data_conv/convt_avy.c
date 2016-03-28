/**** THIS PROGRAM CONCATENATES ALL AVY FILES IN avy_temp.t ***/
/******* IT'S INPUT IS Avy files created by linguistics *******/
/**************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include"/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/avy.h"
main()
{
int ind;
FILE *avy_I_fp,*avy_O_fp;
char ch[LINE_SIZE];
int found,i;

avy_O_fp = fopen("avy_temp.t","w");
for (ind = 0;ind< totfile;++ind)
 {
	if ((avy_I_fp = fopen(filename[ind],"r")) == NULL)
 		printf("ERROR CAN NOT OPEN FILE %s\n",filename[ind]);
        fgetline(ch,avy_I_fp);/*Get file name */
        fgetline(ch,avy_I_fp);
        while(ch[0] != '\0')
         {
          fprintf(avy_O_fp,"%s\n",ch);
          fgetline(ch,avy_I_fp);
         }
 }
fclose(avy_O_fp);
}
