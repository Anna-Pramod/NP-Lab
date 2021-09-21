#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
  
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message1,message2, message3;
  
int main()
{
    key_t key;
    int msgid1,msgid2,msgid3;
  
    // ftok to generate unique key
    key = ftok("progfile", 65);
  
    // msgget creates a message queue
    // and returns identifier
    msgid1 = msgget(key, 0666 | IPC_CREAT);
  
    // msgrcv to receive message
    msgrcv(msgid1, &message1, sizeof(message1), 1, 0);
  
    // display the message
    printf("Data 1 Received is : %s \n", 
                    message1.mesg_text);
  
    // to destroy the message queue
    msgctl(msgid1, IPC_RMID, NULL);
    
    msgid2 = msgget(key, 0666 | IPC_CREAT);
  
    // msgrcv to receive message
    msgrcv(msgid2, &message2, sizeof(message2), 1, 0);
  
    // display the message
    printf("Data 2 Received is : %s \n", 
                    message2.mesg_text);
  
    // to destroy the message queue
    msgctl(msgid2, IPC_RMID, NULL);
    
    
    
    
    msgid3 = msgget(key, 0666 | IPC_CREAT);
  
    // msgrcv to receive message
    msgrcv(msgid3, &message3, sizeof(message3), 1, 0);
  
    // display the message
    printf("Data 3 Received is : %s \n", 
                    message3.mesg_text);
  
    // to destroy the message queue
    msgctl(msgid3, IPC_RMID, NULL);
    
  
    return 0;
}
