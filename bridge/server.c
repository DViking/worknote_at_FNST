/*������һ���ಥ�����������ӡ��ಥ�������ĳ�����ƺܼ򵥣�����һ�����ݰ��׽��֣�ѡ���ಥ��IP��ַ�Ͷ˿ڣ�
ֱ����˶ಥ��ַ�������ݾͿ����ˡ��ಥ�������ĳ�����ƣ�����Ҫ����������ಥ�飬����ֱ����ĳ���ಥ�鷢�����ݡ�
��������ӳ�����ಥIP��ַ"224.0.0.100"��8888�˿ڷ�������"BROADCAST TEST DATA"��ÿ����һ�μ��5s��*/

/*
*broadcast_server.c - �ಥ�������
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>


#define MCAST_PORT 8888
#define MCAST_ADDR "224.1.1.100"    /*һ���ֲ����Ӷಥ��ַ��·����������ת��*/
#define MCAST_DATA "Broadcast test data"            
#define MCAST_INTERVAL  2                            /*���ͼ��ʱ��*/

int main(int argc, char*argv)
{
    int s;
    struct sockaddr_in mcast_addr;     
    s = socket(AF_INET, SOCK_DGRAM, 0);         /*�����׽���*/
    if (s == -1)
    {
        perror("socket()");
        return -1;
    }
   
    memset(&mcast_addr, 0, sizeof(mcast_addr));
    mcast_addr.sin_family = AF_INET;                //����
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);   //IP��ַ
    mcast_addr.sin_port = htons(MCAST_PORT);        //�˿�
   
                                                    /*��ಥ��ַ��������*/
    while(1) {
        int n = sendto(s,                           /*�׽���������*/
               MCAST_DATA,     /*����*/
               sizeof(MCAST_DATA),    /*����*/
               0,
               (struct sockaddr*)&mcast_addr,
               sizeof(mcast_addr)) ;
        if( n < 0)
        {
            perror("sendto()");
            return -2;
        }      
	printf("send ...\n"); //***debug       
        sleep(MCAST_INTERVAL);                          /*�ȴ�һ��ʱ��*/
    }
   
    return 0;
}
