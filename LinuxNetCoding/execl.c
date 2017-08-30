/*************************************************************************
    > File Name: execl.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Mon 31 Jul 2017 11:04:31 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Executing ls -l\n");
	execl("/bin/ls","ls","-l",NULL);

	perror("execl failed to run ls");
	exit(1);

}
