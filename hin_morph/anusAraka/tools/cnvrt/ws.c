#include<stdio.h>
main(argc,argv)
int argc;
char *argv[];
{
char c,line[1000],line1[80];
FILE *fp_r,*fp_w;
int i=0,j=0,k,line_no=1,line_length,para=0,shift=0;
int INSERT =0;

if(argc<3) 
{
	fprintf(stderr,"Usage:ws.out input_file line_length <I>\n");
	exit();
}
if(argc ==4)
	if(strcmp(argv[3],"I")==0 ) INSERT =1; 
line_length = atoi(argv[2]);
fp_r = fopen(argv[1],"r");
while(!feof(fp_r))
{
	fgetline(line,fp_r);
	/*fprintf(stderr,"%d lines read\n\n",line_no++);*/
	c = getc(fp_r);
	if(c == '\t') para = 1;
	ungetc(c,fp_r);
	if(shift == 0) j=0;
	else j = -(i-j+1);
	i=0;

	while(1)
	{
		while(line[i]!='\0' && i<(j+line_length))
			line1[i-j] = line[i++];
        	if ( i<j+line_length-1)
		{
			line1[i-j]='\0';
			if((i-j) > 60 && (!para) )
			{
				del_bl_at_start(line1);
				if(INSERT==1) insrt_space(line1,i-j,line_length);
				else del_blanks(line1);
			}
			if((i-j) < 60 && (!para))
			{
				shift = 1;	
				line1[i-j]=' ';
				break;
			}
			printf("%s\n",line1);
			shift=i=j=0;
			break;
		}
		else 
			if(line[i]!='\0')
			{
				for(k=line_length-1;line1[k]!=' ';k--);
				line1[k]='\0';
				del_bl_at_start(line1);
				if(INSERT ==1) insrt_space(line1,k,line_length);
				else del_blanks(line1);
				printf("%s\n",line1);
				i=j+k;
				j=i;
			}
			else 
			{
				line1[i-j] = line[i];
				del_bl_at_start(line1);
				printf("%s\n",line1);
				shift =0;
				break;
			}
	}
}
line1[i-j]='\0';
del_bl_at_start(line1);
if((i-j) < 60) printf("%s\n",line1);
fclose(fp_r);
}

fgetline(s_ptr,fp)
char *s_ptr;
FILE *fp;
{
char c;
while((c=getc(fp))!='\n' && !feof(fp)) 
{
	*s_ptr++ = c;
}
*s_ptr = '\0';
return;
}

insrt_space(line,count,line_length)
char *line;
int count,line_length;
{
int i,j,word,insrt,remain_count,line_ptr,remain =0,total_spaces=0,letters=0;
char *line1;
int cons_spaces[15];

for (i=0;i<15;i++) cons_spaces[i]=1;
j=word=1;
count = line_length-1-count;
del_blanks(line);
for (i=0;line[i]!='\0';i++)
{
	if(line[i] == ' ' )
	{
		total_spaces++;
		if(line[i-1] ==' ') cons_spaces[j]++;
	}
	else 
		if(line[i-1] == ' ') 
		{
			word++;
			j++;
		}
}
if (word == 1) return;
insrt = (count)/(word-1);
remain_count = (count+total_spaces)%(word-1);
if(remain_count>0) remain = 1;
line_ptr = line_length-1;
for (i=line_length-count-1;i>=0;i--)
{	line[line_ptr--]=line[i];
	if(line[i]==' ')
	{
		if(line[i-1]!=' ')
			for (j=0;j<(insrt+remain) && i<line_ptr;j++)
				line[line_ptr--]=' ';
			if(i == line_ptr  && j<(insrt+remain)) line[line_ptr--] =' ';
			remain_count--;
			word--;
			if(remain_count>0) remain = 1;
			else remain = 0;
	}
}
}

del_bl_at_start(line)
char *line;
{
int i,blanks;
for(i=0;line[i]==' ';i++);
blanks = i;
if (blanks == 0) return;
for(i=0;line[i]!='\0';i++)
line[i] = line[i+blanks];
}

del_blanks(line)
char *line;
{
int i,j=0;
char temp[80];

for(i=0;line[i]!='\0';i++)
	if(line[i] != ' ')
		temp[j++] = line[i];
	else 
		if(line[i+1] != ' ')
			temp[j++] = line[i];
temp[j] = line[i];
strcpy(line,temp);
}
