/*************************************************************************
    > File Name: docommand.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Mon 31 Jul 2017 02:21:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int docommand(char* command){

	int pid;
	switch(pid = fork()){

		case -1:
			return -1;
		case 0:
			execl("/bin/sh","sh","-c",command,NULL);
			exit(127);
		default:
			wait(NULL);
	}
	return 0;
}

int main(){
	char * command = "echo hello world!";
	docommand(command);
	return 0;

}
