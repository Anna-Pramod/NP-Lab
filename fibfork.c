#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void fib(int ip)
{
	int a=0, b=1, n=a+b;
	int i=ip;
	
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("Child is making the fibonacci series.\n");
		printf("0 %d",n);
		while (i>0)
		{
			n = a+b;
			printf(" %d ",n);
			a=b;
			b=n;
			i--;
			if(i==0)
			{
				printf("\nChild ends now.\n");
			}
		}
	}
	else
	{
		printf("Parent is wating for the child to complete.\n");
		waitpid(pid,NULL,0);
		printf("\nParent ends now.\n");
	}
}

int main()
{
	int ip;
	printf("Enter number:\n");
	scanf("%d",&ip);
	fib(ip);
	return 0;
}
