/*************************************************************************
    > File Name: kill.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Wed 02 Aug 2017 02:39:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int ntimes = 0;

int main(){

	int pid,ppid;
	int p_action(),c_action();

	signal(SIGUSR1,p_action);

	switch(pid = fork()){
		case -1:
			perror("synchro");
			exit(1);
		case 0:
			signal(SIGUSR1,c_action);
			ppid = getppid();
			for(;;){
				sleep(1);
				kill(ppid,SIGUSR1);
				pause();
			}
			break;
		default:
			for(;;){
				pause();
				sleep(1);
				kill(pid,SIGUSR1);
			}
	}
}


int p_action(){
	printf("Patent caught signal #%d\n",++ntimes);
}

int c_action(){
	printf("Child caught signal #%d\n",++ntimes);
}

int test(){
	printf("This is a text\n");
}
