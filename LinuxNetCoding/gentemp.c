/*************************************************************************
    > File Name: gentemp.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Tue 01 Aug 2017 05:42:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int num = 0;
static char namebuf[50];
static char prefix[] = "/home/viking/LinuxNetCoding/tmp/tmp";

void itoa(int i, char* string){

	int power, j;

	j=i;

	for(power = 1; j >= 10; j/=10){
		power *= 10;
	}
	for(;power > 0; power /= 10){

		*string++ = '0' + i / power;
		i %= power;
	}
	*string = '\0';
}

char* gentemp(){

	int length, pid;

	pid = getpid();

	strcpy(namebuf, prefix);
	length = strlen(namebuf);

	itoa(pid,&namebuf[length]);

	strcat(namebuf,".");
	length = strlen(namebuf);

	do{
		itoa(num++,&namebuf[length]);

	}while(access(namebuf,0) != -1);

	return namebuf;

}

int main(){

	gentemp();
	return 0;
}
