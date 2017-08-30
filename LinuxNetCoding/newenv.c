/*************************************************************************
    > File Name: newenv.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Wed 02 Aug 2017 01:53:21 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(){

	char * argv[]={
		"showenv",NULL
	},
		 * envp[]={
		"foo=bar","bar=foo",NULL
	};
	execve("./showenv",argv,envp);
	perror("exeve failed.");
	return 0;
}
