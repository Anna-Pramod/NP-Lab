// receiver program
/*read string from the queue and check if palindrome*/

#include <fcntl.h>           
#include <sys/stat.h>        
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
	mqd_t q2;
	char *str;
	struct mq_attr *attr1;
	int len;
	int flag=0;
	
	attr1 = malloc(sizeof(struct mq_attr));
	q2 = mq_open("/palindrome",O_RDWR);
	
	if(q2 == -1)
	{
 		printf("Error");
	}
	
	str = malloc(10*sizeof(char));
	
	mq_getattr(q2, attr1); // to retrive attributes of message queue refferd to by the message queue descriptor q2 and it returns a attr1 structure in the buffer
	
	mq_receive(q2,str,attr1->mq_msgsize,NULL); 
	
	// removes the oldest message with the highest priority from the message queue reffered to by the message descriptor q2, 
	
	//and places it in a buffer pointed to by str, the size of the buffer is mq_msgsize
	
	printf("\nMessage received is: %s\n",str);
	
	// Palindrome Checking section:
	
	//len=strlen(str)-1;
	/*for(int i=0 ; i<=len/2 ; i++)
	{
		if(tolower(m.str[i]) != tolower(m.str[len-1-i]))
		{
			flag= -1;
			break;
		}
		/*
		if(str[i] != str[len-i-1])
		{
			flag= -1;
			break;
		}
		*/
	int n = strlen(str);
	//int flag=0;
	for(int i=0;i<=n/2; i++)
	{
		if(tolower(str[i])!=tolower(str[n-2-i])){
			flag=1;
			break;
	}
	//}
	if(flag)
		printf("\nString is not palindrome");
	else
		printf("\nString is palindrome");
	}

	/*if(flag != -1)
	{
		printf("The string is palindrome.\n");
	}
	else
	{
		printf("The string is NOT palindrome.\n");
	}
	*/

	return 0;
}
