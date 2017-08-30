/*************************************************************************
    > File Name: fifoserver.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Fri 04 Aug 2017 09:07:14 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>

#define FIFO_FILE "sampleFIFO"

int main(){
	FILE *fp;
	char readbuf[80];
	
	/* Create the FIFO if it does not exist */
	umask(0);

	/* Create the FIFO in file system */
	mknod(FIFO_FILE,S_IFIFO|0666,0);

	while(1){
		/* Open the FIFO */
		fp = fopen(FIFO_FILE,"r");

		/* Get data from the FIFO */
		fgets(readbuf,80,fp);
		printf("Received string: %s\n", readbuf);

		/* Close the FIFO */
		fclose(fp);
	}
	return 0;

}
