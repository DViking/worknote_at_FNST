/*下面是一个多播服务器的例子。多播服务器的程序设计很简单，建立一个数据包套接字，选定多播的IP地址和端口，
直接向此多播地址发送数据就可以了。多播服务器的程序设计，不需要服务器加入多播组，可以直接向某个多播组发送数据。
下面的例子持续向多播IP地址"224.0.0.100"的8888端口发送数据"BROADCAST TEST DATA"，每发送一次间隔5s。*/

/*
*broadcast_server.c - 多播服务程序
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>


#define MCAST_PORT 8888
#define MCAST_ADDR "224.1.1.100"    /*一个局部连接多播地址，路由器不进行转发*/
#define MCAST_DATA "Broadcast test data"            
#define MCAST_INTERVAL  2                            /*发送间隔时间*/

int main(int argc, char*argv)
{
    int s;
    struct sockaddr_in mcast_addr;     
    s = socket(AF_INET, SOCK_DGRAM, 0);         /*建立套接字*/
    if (s == -1)
    {
        perror("socket()");
        return -1;
    }
   
    memset(&mcast_addr, 0, sizeof(mcast_addr));
    mcast_addr.sin_family = AF_INET;                //类型
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);   //IP地址
    mcast_addr.sin_port = htons(MCAST_PORT);        //端口
   
                                                    /*向多播地址发送数据*/
    while(1) {
        int n = sendto(s,                           /*套接字描述符*/
               MCAST_DATA,     /*数据*/
               sizeof(MCAST_DATA),    /*长度*/
               0,
               (struct sockaddr*)&mcast_addr,
               sizeof(mcast_addr)) ;
        if( n < 0)
        {
            perror("sendto()");
            return -2;
        }      
	printf("send ...\n"); //***debug       
        sleep(MCAST_INTERVAL);                          /*等待一段时间*/
    }
   
    return 0;
}
