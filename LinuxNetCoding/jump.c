/*************************************************************************
    > File Name: jump.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Thu 03 Aug 2017 02:03:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf position;

int main(){

	int goback();

	setjmp(position);


	signal(SIGINT,goback);

	wait(10);
//	domenu();
	printf("show menu!!\n");


}

goback(){
	fprintf(stderr,"\nInterrupted\n");
	longjmp(position,1);
}
