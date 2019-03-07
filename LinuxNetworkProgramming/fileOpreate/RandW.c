/******************
 * time: 2019/03/07
 * author: IvanChan
 * name: RandW.c
 * purpose: learning to handle file on the linux operate system.
 ******************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/****************************
 * 读取文件的函数：ssize_t read(int fd, void *buf, size_t count)
 * 返回实际读取数据的字节数
 * param:
 *      fd：要读取文件的文件描述符
 *      buf: 读取出数据存放的容器指针
 *      count: 要读取的数据的指定长度
 *      
 * 写入文件的函数：ssize_t write(int fd, void *buf, size_t count)
 * 返回文件写入的字节数
 * param：
 *      fd: 要写入数据的文件的文件描述符
 *      buf: 将要写入文件的数据的缓冲区指针
 *      count: 将要写入文件的数据的长度
 * 操作文件指针移动的函数：off_t lseek(int fildes, off_t offset, int whence)
 * 返回当前的读写位置，就是距离文件开头多少个字节。
 * param:
 *      fildes: 操作文件的文件描述符
 *      offset: 根据whence的值移动读写位置的位移数
 *      whence: 有三种取值 SEEK_SET,SEEK_CUR,SEEK_END
 *          SEEK_SET:从文件开始处计算偏移量，文件开始处到指针位置的距离为offset
 *          SEEK_CUR:从文件指针的当前位置开始计算偏移量，文件指针的指等于当前指针的值加offset的值，offset允许取负数。
 *          SEEK_END:从文件结束处计算偏移量，文件指针值等于当前指针值加上offset值，offset允许取负数。
 *      lseek允许将指针设置到文件的文件结束符(EOF)之后，但是这样并不改变文件的大小。并不影响读写。
 * 常用操作：将文件指针移动到文件开头 lseek(int fildes, 0, SEEK_SET)，将文件指针移动到文件结尾 lseek(int fildes, 0, SEEK_END),
 * 获取读写指针的当前位置（相对文件开头的偏移） lseek(int fildes, 0, SEEK_CUR)
 * 
 ****************************/


void my_err(const char *err_string, int line) {
    fprintf(stderr, "line: %d   ", line);
    perror(err_string);
    exit(1);
}

int my_read(int fd) {
    int len, ret, i;
    char read_buf[64];

    if (lseek(fd, 0, SEEK_END) == -1) {
        my_err("lseek",__LINE__);
    }
    if ((len = lseek(fd, 0, SEEK_CUR)) == -1) {
        my_err("lseek", __LINE__);
    }
    if ((lseek(fd, 0, SEEK_SET)) == -1) {
        my_err("lseek", __LINE__);
    }

    printf("file's len: %d \n", len);

    if ((ret = read(fd, read_buf, len)) < 0) {
        my_err("read", __LINE__);
    }

    for (i=0; i<len; i++) {
        printf("%c", read_buf[i]);
    }
    printf("\n");

    return ret;
    
}

int main() {
    int fd;
    char write_buf[32] = "Hello, World!Hello, World!";

    //if ((fd = creat("example_63.c", S_IRWXU)) == -1) {
    if ((fd = open("example_63.c", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU)) == -1) {
        my_err("open", __LINE__);
    } else {
        printf("create file success \n");
    }

    if (write(fd, write_buf, strlen(write_buf)) != strlen(write_buf)) {
        my_err("write", __LINE__);
    }    
    my_read(fd);

    printf("/*-----------------*/ \n");
    if (lseek(fd, 10, SEEK_END) == -1) {
        my_err("lseek", __LINE__);
    }
    if (write(fd, write_buf, strlen(write_buf)) != strlen(write_buf)) {
        my_err("write", __LINE__);
    }
    my_read(fd);

    close(fd);
    return 0;
    
}
