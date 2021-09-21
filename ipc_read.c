/*Write a program to create a message
queue with read and write permissions to write 3 messages to it with different priority numbers */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10 // maximum size of the message that can be written into the message queue

struct mesg_buffer // structure for message queue
{
    long mesg_type;
    char mesg_text[100]; // to store the data that will be written into the message queue
} message1,message2,message3;

// first read into the buffer and the copied to the variable mesg_text to be finaly written into the message queue using msgsnd function
int main()
{
	key_t key;
	int msgid1,msgid2,msgid3;
	key = ftok("progfile", 65); // ftok to generate unique key
	
	msgid1 = msgget(key, 0666 | IPC_CREAT); // msgget creates a message queue and returns identifier
	message1.mesg_type = 1;
	printf("Write Data 1: ");
	fgets(message1.mesg_text,MAX,stdin);
	
	msgsnd(msgid1, &message1, sizeof(message1), 0); //mq identifier , pointer to the message to be send, controls what happens if the message queue is full or the system limit on the queued message is reached
	
	
	printf("Data send is : %s \n", message1.mesg_text);
	
	msgid2 = msgget(key, 0666 | IPC_CREAT);
	message2.mesg_type = 1;
	
	printf("Write Data 2: ");
    fgets(message2.mesg_text,MAX,stdin);
  
    // msgsnd to send message
    msgsnd(msgid2, &message2, sizeof(message2), 0);
  
    // display the message
    printf("Data send is : %s \n", message2.mesg_text);
    
    
    
    msgid3 = msgget(key, 0666 | IPC_CREAT);
    message3.mesg_type = 1;
  
    printf("Write Data 3: ");
    fgets(message3.mesg_text,MAX,stdin);
  
    // msgsnd to send message
    msgsnd(msgid3, &message3, sizeof(message3), 0);
  
    // display the message
    printf("Data send is : %s \n", message3.mesg_text);
  
	
	return 0;	
}
