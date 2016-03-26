#include<stdio.h>
#include<time.h>
#include<unistd.h>

char * myasctime(); // to generate time stamp, current time in string format

void print_log(FILE *log_file, char *message, char *program_name, char *file_name, int line_no, char *function_name)
{
        if (!log_file)
            return;

	fprintf(log_file, "%s:%s[%d]:%s:%d:%s:%s\n", 
						myasctime(), 
						program_name, 
						getpid(),
						file_name, 
						line_no, 
						function_name,
						message);
	fflush(log_file);
}



void print_err(FILE *log_file, char *message, char *program_name)
{
        if (!log_file)
            return;
	fprintf(log_file, "%s %s[%d] %s\n", myasctime(), program_name, getpid(), message);
	fflush(log_file);
}

char *myasctime()
{ 
	
	static char mon_name[12][3] = { "Jan", 
									"Feb", 
									"Mar", 
									"Apr", 
									"May", 
									"Jun", 
									"Jul", 
									"Aug", 
									"Sep", 
									"Oct", 
									"Nov", 
									"Dec" 
								}; 
	
	static char result[26]; 
	
	struct tm *timeptr;

	time_t t = time('\0');
	timeptr = localtime(&t);

	sprintf(result, "%.3s%3d %.2d:%.2d:%.2d", 
					mon_name[timeptr->tm_mon], 
					timeptr->tm_mday, 
					timeptr->tm_hour, 
					timeptr->tm_min, 
					timeptr->tm_sec); 
	return result; 
}
