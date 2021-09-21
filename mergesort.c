#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int elem[20];

void swap( int *a, int *b )
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void *sort1( void *arg )
{
	int *n = ( int * )arg;
	int k =  ( *n )/2;
	for (int i=0; i<k-1; i++)
	{
		for (int j=0; j<k-i-1; j++)
		{
			if (elem[j]>elem[j+1])
			{
				swap(&elem[j], &elem[j+1]);
			}
		}
	}
	sleep(1);
	printf("\nEnding of Thread 1\n");
}

void *sort2( void* arg )
{
	int *n = (int *)arg;
	int  x = ( *n )/2;
	int  y = ( *n );
	
	for (int i=0; i<y-1; i++)
	{
		for (int j=x; j<y-i-1; j++)
		{
			if (elem[j]>elem[j+1])
			{
				swap(&elem[j], &elem[j+1]);
			}
		}
	}
	sleep(1);
	printf("\nEnding of Thread 2\n");
}

int main()
{
	int n;
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements to be sorted: ");
	for (int i=0; i<n; i++)
	{
		scanf("%d",&elem[i]);
	}
	
	pthread_t tid0;
	pthread_t tid1;
	
	pthread_create(&tid0, NULL, &sort1, &n);
	pthread_create(&tid1, NULL, &sort2, &n);
	
	pthread_join(tid0, NULL);
	pthread_join(tid1, NULL);
	
	int result[20];
	int i=0, j=n/2, k=0;
	
	while(i<n/2)
	{
		result[k] = elem[i];
		i++;
		k++;
	}
	while(j<n)
	{
		result[k] = elem[j];
		j++;
		k++;
	}
	printf("\nMerged array of the 2 sorted lists: ");
	for (int k=0; k<n; k++)
	{
		printf("%d ",result[k]);
	}
	printf("\n");
	return 0;
}
