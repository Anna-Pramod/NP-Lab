//This program creates a child process.
//The parent process will establish a pipe and will send the data to the childusing writing end of the pipe.
//The child proces will receive the data ad print on the screen using the reading end of the pipe.
//There are 2 file descriptors: fd[1]->writing end of pipe fd[0]->reading end of pipe.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int fd[2], n;
	char buffer[20];
	pid_t p;
	pipe(fd); // to create a unidirectional pipe with 2 ends fd[0] and fd[1]
	p=fork();
	if (p>0)
	{
		printf("Parent passing value to child");
		write(fd[1],"hello",6);
		
	}
	else
	{
		printf("\nChild printing the received value.");
		n=read(fd[0],buffer,10);
		write(1,buffer,n);
	}
	return 0;
}

//Parent process creates a unidirectional pipe  using pipe() call and then creates a child process using fork().
//Parent process sends the data by writing to the writing end of the pipe using the fd[1] file descriptor.
//The child process reads this using using the fd[0] file descriptor and stores it in buffer.
//The child process then prints the received data from the buffer onto the screen.

