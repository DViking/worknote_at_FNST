/*************************************************************************
    > File Name: sigint.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Wed 02 Aug 2017 02:26:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int catch(int sig);

int main(){

	signal(SIGINT,catch);

	printf("xixi\n");
	sleep(10);
	printf("end\n");

	return 0;
}

int catch(int sig){

	printf("Catch success!\n");

	return 1;
}
