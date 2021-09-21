#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *threadfunc(void * tid)
{
	long * myID = (long *) tid;
	printf("This is THREAD %ld\n", * myID);
}

int main()
{
	int i;
	pthread_t tid0;
	pthread_t tid1;
	pthread_t tid2;

	pthread_t *arr[]={&tid0,&tid1,&tid2};
	
	for (i=0;i<3;i++)
	{
		pthread_create(arr[i],NULL,threadfunc,(void *)arr[i]);
	}
	
	pthread_exit(NULL);
	
	return 0;
	
}
