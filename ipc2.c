#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	FILE *rd, *fp;
	char buffer[20];
	fp = fopen("pipe1.txt","w");
	rd = popen("ls","r");
	fread(fp,sizeof(char),50,rd);
	
	pclose(rd);
	fclose(fp);
	return 0;	
}
