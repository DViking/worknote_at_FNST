/*************************************************************************
    > File Name: exec_fork.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Mon 31 Jul 2017 01:55:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

#include <stdlib.h>

int main(){

	int pid;

	pid = fork();

	switch(pid){

		case -1:
			perror("fork failed!\n");
			exit(1);

		case 0:
			execl("/bin/ls","ls","-l","--color",NULL);
			perror("execl failed!\n");
			exit(1);
		default:
			wait(NULL);
			printf("ls completed!\n");
			exit(0);
	}
}
