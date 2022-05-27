#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

char *time_stamp(){

	char *timestamp = (char *) malloc(sizeof(char) * 16);
	time_t ltime;
	ltime=time(NULL);
	struct tm *tm;
	tm=localtime(&ltime);
	
	sprintf(timestamp,"%04d %02d %02d %02d %02d %02d", tm->tm_year+1900, tm->tm_mon, 
	tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
	return timestamp;
	}

int main()
{
	printf("Hello");
	printf(" Timestamp: %s\n",time_stamp());

	int i=fork();

	if(!i)
	{
		execlp("sudo", "python", "python", "script.py", (char*) NULL);
	}
	
	i=fork();
	if(!i)
	{
		execlp("sudo", "python", "python", "script1.py", (char*) NULL);
	}
	
	i=fork();
	if(!i)
	{
		execlp("sudo", "python", "python", "script2.py", (char*) NULL);
	}
	
	i=fork();
	if(!i)
	{
		execlp("sudo", "python", "python", "script3.py", (char*) NULL);
	}

}

