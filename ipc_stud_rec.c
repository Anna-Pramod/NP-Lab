// Receiver program
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

typedef struct student
{
	int roll;
	int marks;
}student;

int main()
{
	int temp1, temp2;
	int i, j, min_idx;
	int n=0;
	
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	
	student *stud = (student*) shmat(shmid,(void*)0,0);
	while(stud[n].roll != -1) 
	{
		n++;    // calculates the number of students
	}
	printf("Data read from memory.    Rank\n");
	for (i = 0; i < n; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			if (stud[j].marks > stud[min_idx].marks)
			{
				min_idx = j;
			}
		}
		temp1=stud[i].marks;
		stud[i].marks=stud[min_idx].marks;
		stud[min_idx].marks=temp1;
		temp2=stud[i].roll;
		stud[i].roll=stud[min_idx].roll;
		stud[min_idx].roll=temp2;
	}
	for(int i=0; i<n; i++)
	{
		printf("Roll No.- %d : Marks- %d   %d\n", stud[i].roll,stud[i].marks,i+1);
	}
	shmdt(stud); //detach from shared memory 
	shmctl(shmid,IPC_RMID,NULL); //destroy the shared memory
	
	return 0;
}
