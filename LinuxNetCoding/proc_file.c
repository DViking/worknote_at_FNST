/*************************************************************************
    > File Name: proc_file.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Mon 31 Jul 2017 02:27:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int failure(char* s){

	perror(s);
	exit(1);

}

int printpos(char* string, int fildes){

	long pos;
	if((pos=lseek(fildes,0L,1))<0L)
		failure("lseek failed");
	printf("%s: %ld \n",string,pos);
}

int main(){

	int fd;
	int pid;

	char buf[10];
	if((fd=open("data",O_RDONLY))<0)
		failure("open failed");
	read(fd,buf,10);
	printpos("Before fork",fd);
	if((pid=fork())<0)
		failure("fork failed");
	else if(!pid){

		printpos("Child before read",fd);
		read(fd,buf,10);
		printpos("Child after read",fd);
	}
	else {
		wait(NULL);
		printpos("Parent after wait ", fd);

	}
}
