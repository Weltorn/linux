#ifndef COMMUNICAITON_TCPCLIENT_H
#define COMMUNICAITON_TCPCLIENT_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <memory.h>
#endif //COMMUNICAITON_TCPCLIENT_H
void tcpClient();


//#include "TCPClient.h"
const int bufSize = 1024;
 int client_fd;

void main()
{
	int len = 0;
	tcpClient();
	len=send(client_fd,"hello server!\n",21,0);//发送欢迎信息
 	if(len <= 0){
        perror("no send");
        return;
    }

	close(client_fd);
}
void tcpClient(){ 
    int len;
    struct sockaddr_in remote_addr;
    char buf[bufSize];
    memset(&remote_addr,0, sizeof(remote_addr));
    remote_addr.sin_family=AF_INET;
    remote_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    remote_addr.sin_port=htons(8000);

    /*创建客户端套接字--IPv4协议，面向连接通信，TCP协议*/
    if((client_fd=socket(PF_INET,SOCK_STREAM,0))<0){
        perror("socket error");
        return;
    }
    /*将套接字绑定到服务器的网络地址上*/
    if(connect(client_fd,(struct sockaddr *)&remote_addr, sizeof(struct sockaddr))<0){
        perror("connect error");
        return;
    }
    printf("connected to server\n");
    len=recv(client_fd,buf,bufSize,0);
    printf("get msg :%s",buf);

	len=send(client_fd,"hello server!\n",21,0);//发送欢迎信息
 	if(len <= 0){
        perror("no send");
        return;
    }

    //close(client_fd);

}
