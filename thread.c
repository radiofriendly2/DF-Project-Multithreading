#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	int i=fork();

	if(!i)
	{
		execlp("sudo", "python", "python", "script.py", "/dev/loop9", (char*) NULL);
	}
	
	i=fork();
	if(!i)
	{
		execlp("sudo", "python", "python", "script1.py", (char*) NULL);
	}
	
	i=fork();
	if(!i)
	{
		execlp("sudo", "python", "python", "script2.py", "./file", "-r", "google", (char*) NULL);
	}
	
	i=fork();
	if(!i)
	{
		execlp("sudo", "python", "python", "script3.py", ".file", "-r", "rule.yar", (char*) NULL);
	}

}

