/******************
 * time: 2019/03/07
 * author: IvanChan
 * name: my_create.c
 * purpose: learning to handle file on the linux operate system.
 ******************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/****************************
 * 打开文件的函数：int open(const char *pathname, int flags, mode_t mode)

 * 返回文件描述符
 * param:	
 *      *pathname:要打开或创建的含路径的文件名，
 * 	 	flags:打开文件的方式
 *		    三种类型： O_RDONLY(只读),O_WRONLY(只写),O_RDWR(可读可写)三种标记可以与下面的其他标志或运算
 *		    > O_CREAT: 如果打开的文件不存在则自动创建文件，只有在此时会输入第三个参数mode用来指定创建的文件的存取权限。
 *		    > O_EXCL: 若O_CREAT被设置了，此指令会检查文件是否存在。文件若不存在则创建该文件，若存在则会导致文件打开出错。
 *		    > O_TRUNC: 若文件存在并且以可写的方式打开，此标志会将文件的长度清零，即原文件的数据丢失，但是属性不变。
 *		    > O_APPEND: 所写入的数据会以追加的方式加入到文件后面。
 *		    > O_SYNC: 以同步的方式打开文件，任何对文件的修改都会阻塞直到物理磁盘数据同步之后才返回。
 *		    > O_NOFOLLOW: 如果pathname所指的文件为一符号连接，则会令打开文件失败。linux 内核2.1.126之后才会有。
 *		    > O_DIRECTORY: 如果pathname所指的文件并非为一目录，则会令打开失败。linux内核2.1.126之后才会有。
 *		    > O_NONBLOCK 或 O_NDELAY: 以非阻塞的方式打开文集爱你，对于open及随后的文件对该文件的操作，都会立刻返回。
 *      mode(optional):要创建文件的存取权限
 * 创建文件的函数：int creat(const char *pathname, mode_t mode)
 * 返回文件描述符
 * param：
 *      *pathname:要打开或创建的含路径的文件名,
 *      mode:要创建文件的存取权限
 * 关闭文件的函数：int close(int fd)
 * 返回操作状态0为成功，-1为失败
 * param：
 *      fd:要关闭的文件的文件描述符，由open函数或creat函数得到。
 * 
 ****************************/




int main() { 
    int fd;

    if ((fd = open("RandW.c", O_CREAT|O_EXCL, S_IRUSR|S_IWUSR)) == -1) {
    //if ((fd = creat("example_62.c", S_IRWXU)) == -1) {
        perror("open");
        //printf("open: %s  with errno: %d \n", stderror(errno), errno);
        exit(1);
    } else {
        printf("create file success \n");
    }

    close(fd);
    return 0;
    
}
