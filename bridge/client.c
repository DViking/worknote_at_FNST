/*�ಥ���IP��ַΪ224.0.0.88���˿�Ϊ8888�����ͻ��˽��յ��ಥ�����ݺ󽫴�ӡ������
�ͻ���ֻ���ڼ���ಥ�����ܽ��ܶಥ������ݣ�
��˶ಥ�ͻ����ڽ��նಥ�������֮ǰ��Ҫ�ȼ���ಥ�飬��������Ϻ�Ҫ�˳��ಥ�顣*/

/*
*broadcast_client.c - �ಥ�Ŀͻ���
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>



#define MCAST_PORT 8888
#define MCAST_ADDR "224.1.1.100"     /*һ���ֲ����Ӷಥ��ַ��·����������ת��*/
#define MCAST_INTERVAL 2                        /*���ͼ��ʱ��*/
#define BUFF_SIZE 256                           /*���ջ�������С*/
int main(int argc, char*argv[])
{  
    int s;                                      /*�׽����ļ�������*/
    struct sockaddr_in local_addr;              /*���ص�ַ*/
    int err = -1;
   
    s = socket(AF_INET, SOCK_DGRAM, 0);     /*�����׽���*/
    if (s == -1)
    {
        perror("socket()");
        return -1;
    }  
   
                                                /*��ʼ����ַ*/
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //ʹ��Ĭ�ϵĵ�ַ
    local_addr.sin_port = htons(MCAST_PORT);
   
                                                /*��socket*/
    err = bind(s,(struct sockaddr*)&local_addr, sizeof(local_addr)) ;
    if(err < 0)
    {
        perror("bind()");
        return -2;
    }
   
                                                /*���ûػ����*/
    int loop = 1;
    err = setsockopt(s,IPPROTO_IP, IP_MULTICAST_LOOP,&loop, sizeof(loop));
    if(err < 0)
    {
        perror("setsockopt():IP_MULTICAST_LOOP");
        return -3;
    }
//	else  printf("socket 1 ok \n");
   
    struct ip_mreq mreq;                                    /*����ಥ��*/
    mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR); /*�ಥ��ַ*/
    mreq.imr_interface.s_addr = htonl(INADDR_ANY); /*����ӿ�ΪĬ��*/
    //����ӿ�  �����Ͷ˻���ն����������ϵ�����ӿڼ����IPʱ�����Ͷ˷���ȥ�����ݣ����ն��ղ���������Ҫ�󶨵������IP��
                                                        /*����������ಥ��*/
    err = setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP,&mreq, sizeof(mreq));  //�����������鲥��
    if (err < 0)
    {
        perror("setsockopt():IP_ADD_MEMBERSHIP");
        return -4;
    }
   
    int times = 0;
    int addr_len = 0;
    char buff[BUFF_SIZE];
    int n = 0;
                                        /*ѭ�����նಥ�����Ϣ��5�κ��˳�*/
    for(times = 0;times<100;times++)
    {
        addr_len = sizeof(local_addr);
        memset(buff, 0, BUFF_SIZE);                 /*��ս��ջ�����*/
                                                    /*��������*/
        n = recvfrom(s, buff, BUFF_SIZE, 0,(struct sockaddr*)&local_addr,&addr_len);

        if( n== -1)
        {
            perror("recvfrom()");
        }
                          
        printf("Recv %dst message from server: %s\n", times, buff);
        sleep(MCAST_INTERVAL);
    }
   
                                                    /*�˳��ಥ��*/
    err = setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP,&mreq, sizeof(mreq));   //�˳��鲥��
       
    close(s);
    return 0;
}
