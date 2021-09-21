/*Program to read details of n students in
one process and display rank details of students in another process using shared memory */
// Sender Program
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct student
{
  int roll;
  int marks;
} student;

int main()
{
	int i, n;
	key_t key = ftok("shmfile",65); // to generate an unique key, it uses the pathname and the least significant 8 bits of 65 
	
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	
	student *stud = (student*) shmat(shmid,(void*)0,0);
	
	printf("\nInput the no of Students :");
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
  {
  	stud[i].roll=i+1;
  	printf("\nInput the marks of student %d: ",i+1);
  	scanf("%d",&stud[i].marks);
  }
  
  stud[i].roll=-1;
  stud[i].marks=-1;
  
	shmdt(stud); // it detaches the shared memory segment located at the address specified by stud from the address space of the calling process.
	
	return 0;
}
