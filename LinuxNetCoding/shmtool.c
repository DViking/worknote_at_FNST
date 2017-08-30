/*************************************************************************
    > File Name: shmtool.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Fri 04 Aug 2017 01:57:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

#define SEGSIZE 100
int main(int argc, char *argv[]){
	int wrteshm(int shmid,char *segptr,char *text),
		readshm(int shmid, char *segptr),
		removeshm(int shmid),
		changemode(int shmid,char * mode),
		usage();
	key_t key;
	int shmid,cntr;
	char *segptr;

	if(argc == 1)
		usage();

	key = ftok(".", 'S');

	if((shmid = shmget(key,SEGSIZE,IPC_CREAT|IPC_EXCL|0666)) == -1){
		printf("Shared memory segment exists - opening as client\n");

		if((shmid = shmget(key,SEGSIZE,0)) == -1){
			perror("shmget");
			exit(1);
		}
	}
	else {
		printf("Creating new shared memory segment\n");
	}

	if((segptr = shmat(shmid,0,0)) == -1){

		perror("shmat");
		exit(1);
	}

	switch(tolower(argv[1][0])){
		case 'w':
			writeshm(shmid,segptr,argv[2]);break;
		case 'r':
			readshm(shmid,segptr);break;
		case 'd':
			removeshm(shmid);break;
		case 'm':
			changemode(shmid,argv[2]);break;
		default:
			usage();
	}
}

writeshm(int shmid,char *segptr,char *text){
	strcpy(segptr,text);
	printf("Done...\n");
}

readshm(int shmid,char *segptr){
	printf("segptr:%s\n",segptr);
}

removeshm(int shmid){

	shmctl(shmid,IPC_RMID,0);
	printf("Shared memory segment marked for deletion\n");
}

changemode(int shmid,char * mode){

	struct shmid_ds myshmds;

	shmctl(shmid,IPC_STAT,&myshmds);

	printf("Old permissions were :%o\n",myshmds.shm_perm.mode);

	sscanf(mode, "%o", &myshmds.shm_perm.mode);

	shmctl(shmid,IPC_SET,&myshmds);

	printf("New permissions are : %o\n", myshmds.shm_perm.mode);
}

usage(){
	fprintf(stderr,
			"shmtool - A utility for tinkering with shared memory\n");
	fprintf(stderr,"\nUSAGE:  shmtool			  (w)rite <text>\n");
	fprintf(stderr,"				  (r)ead\n");
	fprintf(stderr,"				  (d)elete\n");
	fprintf(stderr,"				  (m)ode change <octal mode>\n");
	exit(1);

}
