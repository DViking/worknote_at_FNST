/*************************************************************************
    > File Name: showenv.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Wed 02 Aug 2017 11:54:04 AM CST
 ************************************************************************/

#include <stdio.h>


extern char** environ;

int main(){
	char**  env = environ;

	while(*env){
		printf("%s\n",*env++);
	}
	return 0;
}
