/* Check given string is palindrome or not
using IPC mechanism using message passing.
*/
// sender program
/* accept a string from standard input,pass the string into the message queue
*/

#include <fcntl.h>         
#include <sys/stat.h>     
#include <mqueue.h>
#include <stdio.h>
#include <string.h>

int main()
{
	mqd_t q1; //message queue descriptor
	
	char str[40];
	printf("\nInput a string : ");
	fgets(str, 30, stdin);
	
	q1 = mq_open("/palindrome",O_CREAT|O_RDWR,0666,NULL);  
	
	if(q1 == -1) 
	{
  	printf("\nError\n");
  }
  
  mq_send(q1,str,strlen(str),0); // puts a message of size strlen(str) pointed to by str into the queue indicated by q1
	
	return 0;
}
