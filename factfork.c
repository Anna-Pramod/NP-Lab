#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

/* FACTORIAL CALCULATION */

int main( int argc, char *argv[])
{
	pid_t pid;
	if(argc != 2)
	{
		printf("\nThe argument is missing or exceeding\n");
		exit(0);
	}
	
	if( atoi( argv[1] ) < 0)
	{
		printf("\nNegative number entered:%d\n",atoi(argv[1]));
		exit(0);
	}
	
	pid = fork();
	
	if (pid<0)
	{
		printf("\nFailed to create child process: FORK FAILURE\n");
		exit(0);
	}
	else if(pid == 0)
	{
		/* CHILD PROCESS */
		int ans=0, i, j, n, k=2;
		
		n = atoi(argv[1]);
		int arr[n], sum[n];
		
		arr[0] = 1;
		
		/* FACTORIAL SERIES */
		
		for(i=1; i<n; i++)
		{
			arr[i] = arr[i-1] * k;
			k++;
		}
		
		for(i=0; i<n; i++)
		{
			printf(" %d ",arr[i]);
		}

		/*for(j=0; j<n; j++)
		{
			sum[j] = 0;
			for(i=0; i<=j; i++)
			{
				printf(" %d ",arr[i]);
				sum[j] += arr[i];
			}
			printf("\n");
		}*/
	}
	
	
	return 0;
}
