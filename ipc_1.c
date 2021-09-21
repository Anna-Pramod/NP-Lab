/* Write a program to implement the following scenario. First process accepts sentences and writes on one pipe to be read by second process and second process counts number of characters, number of words and number of lines in accepted sentences, writes this output in a text file and writes the contents of the file on second pipe to be read by first process and displays on standard output. */
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>

int fd1[2], fd2[2];
int word=0, line=0, charac=0,  n;
pid_t p1;

char inpstr[100], st1[100], result[100], st2[100];
FILE *fptr;

int main()
{
	if (pipe(fd1)==-1)
	{
		printf("Pipe Failed");
	}
	if (pipe(fd2)==-1)
	{
		printf("Pipe Failed");
	}
	p1 = fork();
	if (p1 < 0)
	{
		printf("Fork Failed");
	}
	if (p1>0)  // parent process
	{
		close(fd1[0]);// since parent process writes into the first pipe, reading end of first pipe fd1[0] is closed
		printf("\nEnter the Sentence: ");
		scanf("%[^~]",&inpstr);
		//fgets(inpstr,100,stdin); // input sentence is stored in inpstr string
		n = strlen(inpstr) + 1;
		if ( write(fd1[1], inpstr, 100) == -1 ) // storing the input string to the pipe
		{
			printf("\nError while writing");
			return 1;
		}
		close(fd1[1]);//closing the writing end of the first pipe
		wait(NULL);  // wait for the child process to terminate and next the child process starts reading from the pipe through the reading end of the second pipe
		close(fd2[1]); //closing the writing end of the second pipe 
		for (int i=0; i<3; i++) // since we are giving 3 lines as input
		{
			read(fd2[0],st2,100); //child process reads the file through the reading end of the second pipe fd2[0] into the string st2
			printf("%s",st2);
		}
		close(fd2[0]);
	}
	else //child process
	{
		close(fd1[1]);//closing the writing end of the first pipe because the child process starts to read the string through fd1[0] reading end 
		if (read(fd1[0],st1,100)==-1)
		{
			printf("\nError while reading.");
			return 1;
		}
		printf("\nString is: %s",st1);
		close(fd1[0]);// reading end to the child process of the pipe is closed
		for (int i=0; st1[i]!='\0';i++)
		{
			if (st1[i] == ' ')
			{
				word++;
			}
			else if (st1[i] == '\n')
			{
				line++;
			}
			else if (isalpha(st1[i]))
			{
				charac++;
			}
		}
		fptr = fopen("pipe1.txt","w");// Saved onto this file
		fprintf(fptr, "\nNo of Characters = %d\n",charac);
		fprintf(fptr, "\nNo of words = %d\n",(word+1));
		fprintf(fptr, "\nNo of sentences = %d\n",line);
		fclose(fptr);
		fptr = fopen("pipe1.txt","r");//reading from the text file
		close(fd2[0]);// and is written into the second pipe, hence closing the reading end of the second pipe.
		while ( fgets(result,100,fptr) != NULL)// until the file pointer fptr is NULL the content of the text file is written into the second pipe. ( first it is written into result string)
		{
			n = strlen(result)+1;
			if (write(fd2[1],result,100)==-1)// writing into seconnd pipe
			{
				printf("\nError while writing.");
				return 1;
			}
		}
		fclose(fptr);
		close(fd2[1]);
	}
		 
	return 0;
}
