/* Write a program to
create two processes P1 and P2. P1 takes a string and passes it to P2. P2
concatenates the received string with another string without using string
function and sends it back to P1 for printing.(using fork()
and pipe())
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{

	int fd1[2], fd2[2];
	char str1[40], str2[40];
	pid_t p;
	
	if (pipe(fd1)==-1)
  {
    printf("Pipe 1 Failed" );
    return 1;
  }
  
  if (pipe(fd2)==-1)
  {
    printf("Pipe 2 Failed" );
    return 1;
  }
  
  printf("Input the first string : ");	
  fgets(str1,40,stdin);
  printf("Input the string that has to be concatenated with : ");
  fgets(str2,40,stdin);
  p = fork();
  
  if (p < 0)
  {
		printf("Fork Failed");
		return 1;
	}
	
	else if (p > 0)
	{
		char concat[100];
		close(fd1[0]); 
		write(fd1[1], str1, strlen(str1)+1); 
		close(fd1[1]);
		wait(NULL);
		close(fd2[1]);
		read(fd2[0], concat, 100);
		close(fd2[0]);
		close(fd2[1]);
    close(fd1[1]);
		printf("Concatenated string is : %s", concat);
		
	}
	
	else
  {
  	close(fd1[1]);
  	char concat[100];
  	read(fd1[0], concat, 100);
  	int k = (strlen(concat)-1);
  	int i;
  	printf("%d",k);
    for (i=0; i<strlen(str2); i++)
    	concat[k++] = str2[i];
    concat[k] = '\0'; 
    
    write(fd2[1], concat, strlen(concat)+1);
    close(fd2[1]);
    close(fd1[1]);
    close(fd1[0]);
    exit(0);
  }
	
  
	return 0;
	
}
