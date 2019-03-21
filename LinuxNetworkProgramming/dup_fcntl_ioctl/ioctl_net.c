/******************
 * time: 2019/03/08
 * author: IvanChan
 * name: ioctl_net.c
 * purpose: learning to and handling file descriptor
 * to handling special devices files on the linux operate system.
 * 示例： ioctl的使用
 ******************/

/*******************
 * ioctl函数： int ioctl(int fd, int request, ....);
 * ioctl函数（系统调用）用来控制设备，能用其他文件操作函数操作的文件都用它来控制。
 * 用来控制特殊设备文件的属性，
 * 底层 glibc 库的if.h中的ifreq结构体似乎被忽略了
 *
 * usr/include/net/if.h
 * struct ifreq
 * 
 * __USE_MISC --> Define things common to BSD and System V Unix.
 * 
 *******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>

unsigned char g_eth_name[16];
unsigned char g_macaddr[6];
unsigned int g_subnetmask;
unsigned int g_ipaddr;
unsigned int g_broadcast_ipaddr;

// void init_net(void)
// {
//     int i, sock;
//     struct sockaddr_in sin;
//     struct ifreq ifr;

//     sock = socket(AF_INET, SOCK_DGRAM, 0);
//     if (sock == -1)
//     {
//         perror("socket");
//     }
//     strcpy(g_eth_name, "eht0");
//     strcpy(ifr.ifr_name, g_eth_name);
//     printf("eth name: \t%s\n", g_eth_name);

//     if (ioctl(sock, SIOCGIFHWADDR, &ifr))
//     {
//         perror("ioctl");
//     }
//     memcpy(g_macaddr, ifr.ifr_hwaddr.sa_data, 6);

//     printf("local mac: \t");
//     for (i = 0; i < 5; i++)
//     {
//         printf("%.2x:", g_macaddr[i]);
//     }
//     printf("%.2x:", g_macaddr);

//     if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
//         perror("ioctl");
//     }
//     memcpy(&sin, &ifr.ifr_addr, sizeof(sin));
//     g_ipaddr = sin.sin_addr.s_addr;
//     printf("local eth0: \t%s\n", inet_ntoa(sin.sin_addr));

//     if (ioctl(sock, SIOCGIFBRDADDR, &ifr) < 0) {
//         perror("ioctl");
//     }
//     memcpy(&sin, &ifr.ifr_addr, sizeof(sin));
//     g_broadcast_ipaddr = sin.sin_addr.s_addr;
//     printf("broadcast: \t%s\n", inet_ntoa(sin.sin_addr));

//     if (ioctl(sock,SIOCGIFNETMASK, &ifr) < 0) {
//         perror("ioctl");
//     }
//     memcpy(&sin, &ifr.ifr_addr, sizeof(sin));
//     g_subnetmask = sin.sin_addr.s_addr;
//     printf("subnetmask: \t%s\n", inet_ntoa(sin.sin_addr));

//     close(sock);
    
// }

// int main() {
//     init_net();
//     return 0;
// }
