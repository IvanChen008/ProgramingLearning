/*****************************
 * time: 2019/03/05
 * author: ivanchem 
 * purpose: learning Linux C programming 
 * name: my_client.c
 *****************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "my_recv.h"

#define INVALID_USERINFO 'n'
#define VALID_USERINFO 'y'

/************** 
 * fetch the userinfo to save to the buf, the length of buf is len,
 * the data of user inputed end up with the sign of '\n' 
 **************/
int get_userinfo(char *buf, int len)
{
    int i;
    int c;

    if (buf == NULL)
    {
        return -1;
    }

    i = 0;
    while ((c = getchar() != '\n') && (c != EOF) && (i < len - 2))
    {
        buf[i++] = c;
    }
    buf[i++] = '\n';
    buf[i++] = '\0';

    return 0;
}

/* input username,then send it by fd  */
void input_userinfo(int conn_fd, const char *string)
{
    char input_buf[32];
    char recv_buf[BUFSIZE];
    int flag_userinfo;

    // input userinfo until the info is right
    do
    {
        printf("%s", string);
        if (get_userinfo(input_buf, 32) < 0)
        {
            printf("error return from get_userinfo\n");
            exit(1);
        }

        if (send(conn_fd, input_buf, strlen(input_buf), 0) < 0)
        {
            my_err("send", __LINE__);
        }

        if (my_recv(conn_fd, recv_buf, sizeof(recv_buf)) < 0)
        {
            printf("data is too long \n");
            exit(1);
        }

        if (recv_buf[0] == VALID_USERINFO)
        {
            flag_userinfo = VALID_USERINFO;
        } else {
            printf("%s error, input again,", string);
            flag_userinfo = INVALID_USERINFO;
        }

    } while (flag_userinfo == INVALID_USERINFO);
}

int main(int argc, char *argv[])
{
    int i;
    int ret;
    int conn_fd;
    int serv_port;
    struct sockaddr_in serv_addr;
    char recv_buf[BUFSIZE];

    /* check number of arguments */
    if (argc != 5)
    {
        printf("Usage: [-p] [serv_port] [-a] [serv_address] \n");
        exit(1);
    }
    // init structure of server address
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    // accept server port and address from commandline
    for (i = 0; i < argc; i++) {
        if (strcmp("-p", argv[i]) == 0) {
            serv_port = atoi(argv[i + 1]);
            if (serv_port < 0 || serv_port > 65535) {
                printf("invalid serv_addr.sin_port \n");
                exit(1);
            } else {
                serv_addr.sin_port = htons(serv_port);
            }
            continue;
        }
        if (strcmp("-a", argv[i]) == 0) {
            if (inet_aton(argv[i + 1], &serv_addr.sin_addr) == 0) {
                printf("invalid server ip address \n");
                exit(1);
            }
            continue;
        }
    }

    // check whether some item of arguments is missing
    if (serv_addr.sin_port == 0 || serv_addr.sin_addr.s_addr == 0) {
        printf("Usage: [-p] [serv_addr.sin_port] [-a][serv_address] \n");
        exit(1);
    }

    // create a TCP socket
    conn_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn_fd < 0) {
        my_err("socket", __LINE__);
    }

    // send a connection request to server side 
    if (connect(conn_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) < 0) {
        my_err("connect", __LINE__);
    }

    input_userinfo(conn_fd, "username:");
    input_userinfo(conn_fd, "password:");

    if ((ret = my_recv(conn_fd, recv_buf, sizeof(recv_buf))) < 0) {
        printf("data is too long \n");
        exit(1);
    }

    for(i = 0; i < ret; i++) {
        printf("%c", recv_buf[i]);
    }

    printf("\n");

    close(conn_fd);
    return 0;
    

}
