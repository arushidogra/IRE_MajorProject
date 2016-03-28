#include<stdio.h>
main()
{
int choice1,choice2,choice3;
char ch[4];

         printf("\n\n\n\n");
	 printf("\t1 CHANGED .p FILES\n");
	 printf("\t2 CHANGED .t FILES\n");
	 printf("\t3 CHANGED avy FILES\n");
	 printf("\t4 CHANGED .p, .t & avy.t FILES\n");
	 printf("\t5 CHANGED Ce , FE , Ca , map_file FILES\n");
	 printf("\t6 CHANGED ALL FILES\n");
	 printf("\t7 QUIT\n");
         printf("\n\n\n\t ENTER YOUR CHOICE  : ");
         scanf("%d",&choice2);
	 system("clear");

         if ((choice2==2)||(choice2==4)||(choice2 == 6))
          {
                printf("\n\t 1 FLAT FILE\n");
                printf("\n\t 2 TABULAR FORMAT \n");
                printf("\n\tENTER CHOICE  :  ");
                scanf("%d",&choice3);
          }
         if (choice2 == 1)
          { 	
		system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_suff.sh");
         	system("cc -g -c ../c_data/const.c");
                system("cc -g -c ../c_data/suff_info.c");
         	system("cc -g -o morph.out *.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/test/*.o");
          }
         else
          if (choice2 == 2)
           {
                if (choice3 == 1)
	 	system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_lex1.sh");
                else if (choice3 == 2)
	 	system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_lex2.sh");
         	system("cc -g -c ../c_data/const.c") ;
                system("cc -g -c ../c_data/lex.c");
         	system("cc -g -o morph.out *.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/test/*.o");
           }
          else
           if (choice2 == 3)
            {
	 	system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_avy.sh");
         	system("cc -g -c ../c_data/const.c");
                system("cc -g -c ../c_data/avy.c");
         	system("cc -g -o morph.out *.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/test/*.o");
            }
           else
            if(choice2 == 4)
             {
                if (choice3 == 1)
	 	system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_lex1.sh");
                else if (choice3 == 2)
	 	system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_lex2.sh");
		system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_suff.sh");
	 	system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_avy.sh");
                system("cc -g -c ../c_data/avy.c");
                system("cc -g -c ../c_data/suff_info.c");
         	system("cc -g -c ../c_data/const.c") ;
                system("cc -g -c ../c_data/lex.c");
         	system("cc -g -o morph.out *.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/test/*.o");
             }
            if(choice2 == 5)
             {
             system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main_fe_suff.sh");
                system("cc -g -c ../c_data/suff_info.c");
         	system("cc -g -c ../c_data/const.c") ;
                system("cc -g -c ../c_data/lex.c");
                system("cc -g -c ../c_data/feature_value.c");
         	system("cc -g -o morph.out *.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/test/*.o");
              }
            if (choice2 == 6)
             {
                if (choice3 == 1)
                  {
                   printf("Is it for KANNADA (y/n)?\n");
                   scanf("%s",ch);
                   if((ch[0]=='y')||(ch[0]=='Y'))
	 	   system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main1_kan.sh");
                   else
	 	   system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main1.sh");
                  }
                else if (choice3 == 2)
	 	   system("sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/data_conv/main2.sh");
                system("cc -g -c ../c_data/lex.c");
                system("cc -g -c ../c_data/avy.c");
         	system("cc -g -c ../c_data/const.c");
                system("cc -g -c ../c_data/suff_info.c");
                system("cc -g -c ../c_data/feature_value.c");
         	system("cc -g -o morph.out *.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/mt/com/morph/test/*.o");
             }
}
