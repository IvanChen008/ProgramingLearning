/*****************************
 * time: 2019/02/28
 * author: ivanchem 
 * purpose: learning Linux C programming 
 * name: my_server.c
 *****************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include "my_recv.h"

#define SERV_PORT   4507 // server port 
#define LISTENQ     12   // link request longest length

#define INVALID_USERINFO    'n'
#define VALID_USERINFO      'y'

#define USERNAME
#define PASSWORD

struct userinfo
{
    char username[32];
    char password[32];
};

struct userinfo users[] = 
{   
    {"linux", "unix"},
    {"4507", "4508"},
    {"clh", "clh"},
    {"xl", "xl"},
    {" ", " "}
};

int find_name(const char *name) {
    int i;

    if(name == NULL) {
        printf("in find_name, NULL pointer");
        return -2;
    }

    for(i = 0; users[i].username[0] != ' '; i++)
    {
        if (strcmp(users[i].username, name) == 0) {
            return i;
        }
    }

    return -1;
}

void send_data(int conn_fd, const char *string) {
    if (send(conn_fd, string, strlen(string), 0) < 0) {
        my_err("send", __LINE__);
    }
}

int main() {

    

}



