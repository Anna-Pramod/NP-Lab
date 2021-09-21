#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int arr1[10][10], arr2[10][10];
int m=0, n=0, p=0, q=0, i=0, j=0,k=0;

void *multifunc ()
{
	int *result = malloc( sizeof( int ));
	*result = arr1[i][k] * arr2[k][j];
	
	//pthread_exit( result );
	return (void*) result;
}

int main()
{
	pthread_t t1;
	int *res;
	printf("\nEnter dimensions: ");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("\nEnter values: ");
	for (i=0;i<m;i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
		
	}
	printf("\nEnter dimensions: ");
	scanf("%d", &p);
	scanf("%d", &q);

	if (n!=p)
	{
		printf("\nCondition not satisfied.\n");
		exit(0);
	}
	else
	{
		printf ("\nEnter Values: ");
		for (i=0;i<p;i++)
		{
			for (j=0; j<q; j++)
			{
				scanf("%d", &arr2[i][j]);
			}
		}
	}
	int mul[m][q];
	for (i=0;i<m;i++)
	{
		for (j=0; j<q; j++)
		{
			mul[i][j]=0;
			for (k=0; k<n; k++)
			{
				pthread_create(&t1, NULL, &multifunc, NULL);
				pthread_join(t1, (void *)&res);
				mul[i][j] = mul[i][j] + *res;
			}
		}
	}
	printf("\nResult Matrix: \n");
	for (i=0;i<m;i++)
	{
		for (j=0; j<q; j++)
		{
			printf("%d ", mul[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
