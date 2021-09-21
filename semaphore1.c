#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>

#define thread_num 4

sem_t semaphore;

void* threadfunc( void* args)
{
	int index = *(int*)args;
	int sem_val;
	sem_wait(&semaphore);
	sem_getvalue(&semaphore, &sem_val);
	printf("%d) Current Semaphore Value after WAIT is: %d\n", index, sem_val);
	sem_post(&semaphore);
	sem_getvalue(&semaphore, &sem_val);
	printf("%d) Current Semaphore Value after POST is: %d\n", index, sem_val);
	free(args);
}

int main()
{
	pthread_t threads[thread_num];
	
	sem_init(&semaphore, 0, 4);
	
	int i;
	for (i=0; i<thread_num; i++)
	{
		int* a = malloc(sizeof(int));
		*a = i;
		pthread_create(&threads[i],NULL,&threadfunc, a);
	}
	for (i=0; i<thread_num; i++)
	{
		pthread_join(threads[i],NULL);
	}
	sem_destroy(&semaphore);
	
	return 0;
}
