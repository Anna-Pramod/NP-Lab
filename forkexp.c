#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid, pid1, pid2;
	
	pid = fork();
	if(pid == 0)
	{
		/* FIRST CHILD NEEDS TO BE PRINTED LATER HENCE THIS PROCESS IS MADE TO SLEEP FOR 3 SECONDS
		FIRST CHILD TERMINATES BEFORE PARENT AND AFTER SECOND CHILD */
		sleep(3);
		/* THIS IS THE FIRST CHILD PROCESS getpid() GIVES THE PROCESS ID AND getppid() GIVES THE PARENT ID OF THAT PROCESS */
		printf("FIRST CHILD:: Child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
	}
	else
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			/*SECOND CHILD TERMINATES AFTER LAST AND BEFORE FIRST CHILD*/
			sleep(2);
			printf("SECOND CHILD:: Child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
		}	
		else
		{
			pid2 = fork();
			if (pid2 == 0)
			{
				/* THIRD CHILD TERMINATES FIRST (which is to be printed first) */
				
				printf("THIRD CHILD:: Child[3] --> pid = %d and ppid = %d\n", getpid(), getppid());
			}
			else
			{
				/* PARENT PROCESS TERMINATES AT LAST
				THIS IS TO BE PRINTED AT LAST*/
				sleep(4);
				printf("PARENT --> pid = %d\n", getpid());
			}
		}
	}
	
	
	
	return 0;
}
