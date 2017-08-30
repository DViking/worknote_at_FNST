/*************************************************************************
    > File Name: httptest.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Fri 18 Aug 2017 11:23:03 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char * argv[]){

	struct hostent * site;

	if(argc != 2){
		fprintf(stderr,"usage: getip address\n");
		exit(1);
	}


	if((site = gethostbyname(argv[1])) == NULL){
		herror("Error at gethostbyname!\n");
		exit(1);
	}


	printf("Host name ; %s\n", site -> h_name);

	printf("IP Address : %s\n",
			inet_ntoa(*((struct in_addr *)site -> h_addr_list[0])));
	return 0;
}
