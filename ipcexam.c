#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include <sys/wait.h>

#define MAX 30

void main()
{
	int p1[2],p2[2],p3[2],p4[2],p5[2],p6[2];
	pid_t pid,ch1,ch2;
	if(pipe(p1)<0)
   {
    printf("faliure");
    exit(0);
   }
   if(pipe(p2)<0)
   {
    printf("faliure");
    exit(0);
   }
   if(pipe(p3)<0)
   {
     printf("faliure"); 
     exit(0); 
   }
    if(pipe(p4)<0)
   {
     printf("faliure");  
     exit(0);
   }
    if(pipe(p5)<0)
   {
     printf("faliure");  
     exit(0);
   }
    if(pipe(p6)<0)
   {
     printf("faliure"); 
     exit(0); 
   }
  pid=fork();
  if(pid<0)
  {
    printf("faliure");
    exit(0);
  }
  else if(p>0) //parent process
  {
      close(p1[0]); //reading end is closed
      close(p3[0]);
      close(p5[0]);
      
      int arr[MAX];
      int n,i;
      int a=0,b=0,c=0;
      
      printf("Enter the number of elements in the array: "); // parent process gets the number array
      scanf("%d",&n);
      for(i=0;i<n;i++)
     {
        scanf("%d",&arr[i]);
     }
     
     int child1[MAX],child2[MAX],child3[MAX];
     
     for(i=0;i<n;i++)
     {
        if(i%3==0)
       {
           child1[a]=arr[i];
           a=a+1;
       }
       else if(i%3==1)
      {
           child2[b]=arr[i];
           b=b+1;
      }    
      else
      {
            child3[c]=child3[i];
            c=c+1;    
      }    
    }
         
         
         write(p1[1],child1,MAX);
         close(p1[1]);
         
         write(p3[1],child2,MAX);
         close(p3[1]);
         
         write(p5[1],child3,MAX);
         close(p5[1]);
         
         wait(NULL); // so that it will block the parent process until any of its child has finished
         
         read(p2[0],child1,MAX);
         read(p4[0],child2,MAX);
         read(p6[0],child3,MAX);
         
         int mx1,mx2,mx3;
         
         mx1=child1[0];
         mX2=child2[0];
         mx3=child3[0];
         
         n=0;
         
         for(i=0;i<a;i++)  // to find the max of first child's array
             {
               if(mx1<child1[i])
                      {
                      	mx1=child1[i];
                      }
               arr[n]=child1[i];
               n=n+1;      
             }
             
         printf("Maximum of first subset is %d\n",mx1);
         
         for(i=0;i<b;i++)
               {
               if(mx2<child2[i])
                      {
                      	mx2=child2[i];
                      }
                arr[n]=child2[i];
                n=n+1;        
             }
             
         printf("Maximum of second subset is %d\n",mx2);
         
         for(i=0;i<c;i++)
        {
               if(mx3<child3[i])
                      {	
                      	mx3=child3[i];
                      }
               arr[n]=child3[i];
               n=n+1;        
        }
        
       printf("Maximum of third subset is %d\n",mx3);  
       
       close(p2[0]);
       close(p2[1]);
       
       close(p4[0]);
       close(p4[1]);
       
       close(p6[0]);
       close(p6[1]);
       
       close(p1[1]);
       
       close(p3[1]);
       
       close(p5[1]);
               
}
