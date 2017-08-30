/*************************************************************************
    > File Name: fifoclient.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Fri 04 Aug 2017 09:25:06 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define FIFO_FILE "sampleFIFO"

int main(int argc,char *argv[]){
	FILE *fp;

	if(argc != 2){
		printf("USAGE: fifoclient [string]\n");
		exit(1);
	}

	/* Open the FIFO */
	if((fp = fopen(FIFO_FILE,"w")) == NULL){
		perror("fopen");
		exit(1);
	}

	/* Write data to FIFO*/
	fputs(argv[1],fp);

	/* Close FIFO*/
	fclose(fp);
	return 0;
}
