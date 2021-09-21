#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *threadfunc(void *var)
{
	//int id = (intptr_t) var;	
	printf("Thread from function %p \n",var);
	sleep(1);
	printf("Exiting from function %p \n",var);
}

int main()
{
	int i;
	pthread_t id;
	printf("Thread Created \n \n");
	for (i=0; i<3; i++)
	{
		pthread_create(&id, NULL, threadfunc,(void *)i);
	}
	pthread_join(id, NULL);
	printf("Joined Thread \n \n");
	
	exit(0);
}
//cast to pointer from integer of different size [-wint-to-pointer-cast] pthread_create(&id, null, threadfunc,(void *)i);
