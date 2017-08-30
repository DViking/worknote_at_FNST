/*************************************************************************
    > File Name: alarm.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Thu 03 Aug 2017 11:20:43 AM CST
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define TIMEOUT 5
#define MAXTRIES 5
#define LINESIZE 100
#define BELL '\007'
#define TRUE 1
#define FALSE 0


static int time_out;

static char inputline[LINESIZE];
char* quickreply(char* prompt);

int main(){

	printf("%s\n", quickreply("Input"));
	return 0;
}

 
char* quickreply(char* prompt){
	int (*was)(), catch(),ntries;

	char* answer;

	was = signal(SIGALRM,catch);

	for(ntries = 0;ntries < MAXTRIES; ntries++){
		time_out = FALSE;
		printf("\n%s>",prompt);

		alarm(TIMEOUT);

		answer = gets(inputline);

		alarm(0);

		if(!time_out){
			break;
		}

	}

	signal(SIGALRM, was);

	return (time_out ? ((char*)0):answer);
}

catch() {
	time_out = TRUE;

	putchar(BELL);

	
}
