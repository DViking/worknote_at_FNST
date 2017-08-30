/*************************************************************************
    > File Name: filelock.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Fri 04 Aug 2017 10:15:11 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SEQFILE "./sequo"
#define MAXBUF 100

int main(){
	int my_lock(),my_unlock();
	int fd,i,n,pid,seqno = 1;
	char buff[MAXBUF + 1];

	pid = getpid();
	if((fd = open("data", O_RDWR | O_CREAT)) < 0){
		perror("Can't open");
		exit(1);
	}
	for(i = 0; i < 5; i++){
		my_lock(fd);
		lseek(fd,01,0);

		if((n = read(fd,buff,MAXBUF)) <= 0){
			perror("read error");
			exit(1);
		}
		buff[n] = 0;
		if(!(n = sscanf(buff,"%d\n",&seqno))){
			perror("sscanf error");
			exit(1);
		}
		printf("pid = %d, seq#=%d\n",pid,seqno);
		seqno++;
		sprintf(buff,"%03d\n",seqno);
		n = strlen(buff);
		lseek(fd,01,0);
		if(write(fd,buff,n) != n){
			perror("write error");
			exit(1);
		}
		my_unlock();
	}
	close(fd);
	
}

my_lock(int fd){
	//system V lock
	/*lseek(fd,0L,0);
	if(lockf(fd,F_LOCK,0L) == -1){
		perror("can`t F_LOCK");
		exit(1);
	}
	return;
	*/

	/*BSD*/
	if(flock(fd,LOCK_EX) == -1){
		perror("can`t LOCK_EX");
		exit(1);
	}


}

my_unlock(int fd){
	/*lseek(fd,0L,0);
	if(lockf(fd,F_ULOCK,0L) == -1){
		perror("can`t F_UNLOCK");
		exit(1);
	}
	return;*/

	/*BSD*/
	if(flock(fd,LOCK_UN) == -1){
		perror("can`t LOCK_UN");
		exit(1);
	}
}
