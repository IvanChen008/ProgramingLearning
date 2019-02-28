/*****************************
 * time: 2019/02/28
 * author: ivanchem 
 * purpose: learning Linux C programming 
 * name: my_recv.h
 *****************************/

#ifndef  __MY_RECV_H

#define __MY_RECV_H
    #define BUFSIZE 1024
    void my_err(const char * err_string, int line);
    int my_recv(int conn_fd, char *data_buf, int len);
#endif