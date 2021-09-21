//Program to write into a pipe
//To open the pipe in write mode and send data from one process to another process
#include<stdio.h>
#include<string.h>

int main()
{
	char buffer[20];
	FILE *rd;
	sprintf(buffer,"name first");
	rd = popen("wc -m", "w");
	fwrite(buffer,sizeof(char),strlen(buffer),rd);
	
	pclose(rd);
	
	return 0;
}
