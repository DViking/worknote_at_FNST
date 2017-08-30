/*************************************************************************
    > File Name: shmcopy.c
    > Author: Ding Weiqin
    > Mail: D_viking@163.com 
    > Created Time: Fri 04 Aug 2017 04:08:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHMKEY1_t (key_t)0x10
#define SHMKEY2 (key_t)0x15

#define SEMKEY (key_t)0x20

#define SIZ 5*BUFSIZ

struct databuf{

	int d_nread;
	char d_buf[SIZ];
};


