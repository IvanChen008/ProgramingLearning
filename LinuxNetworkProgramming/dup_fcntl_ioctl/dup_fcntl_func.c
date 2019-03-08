/******************
 * time: 2019/03/08
 * author: IvanChan
 * name: dup_fcntl_func.c
 * purpose: learning to duplicating files and handling file descriptor
 * to change file properties on the linux operate system.
 ******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
// #include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


/****************************
 * 复制文件描述符的函数：
 *      int dup(int oldfd);
 *      int dup2(int oldfd, int newfd);
 * dup用来复制参数oldfd所指的文件描述符。成功之后返回最小的尚未被使用的描述符，一个
 * 新的描述符和参数oldfd指向同一文件，共享所有锁定、读写指针和各项权限和标志。
 * param:
 *      oldfd：要复制描述符的文件的描述符
 *      newfd: 指定的新的文件描述符的数值（如果newfd已经被程序使用了，系统就会将其
 *      关闭来释放该文件描述符；如果新旧描述符相等，dup2返回new不关闭它。成功返回新
 *      的描述符，失败返回-1）
 *      
 *      
 * 文件控制的函数 fcntl (file control)：
 *      int fcntl(int fd, int cmd);
 *      int fcntl(int fd, int cmd, long arg);
 *      int fcntl(int fd, int cmd, struct flock *lock);
 * 对已经打开的文件描述符，进行操作来改变文件的各种属性。
 * param：
 *      fd: 要操作的文件的文件描述符
 *      cmd: 对文件的操作的选择，一共分五类操作
 *      arg: 
 *      lock: 
 * 
 * 
 * cmd不同对应的五种功能：
 *      cmd=F_DUPFD：复制一个现有的描述符
 *      cmd=F_GETFD或F_SETFD：获得/设置文件描述符标志
 *      cmd=F_GETFL或F_SETFL：获得/设置文件状态标志
 *      cmd=F_GETOWN或F_SETOWN：获得/设置异步I/O所有权
 *      cmd=F_GETLK,F_SETLK或F_SETLKW：获得/设置记录锁
 * 
 ****************************/

void my_err(const char *err_string, int line) {
    fprintf(stderr, "line: %d ", line);
    perror(err_string);
    exit(1);
}

int main() {
    int ret, access_mode, fd;
    if((fd = open("example_64", O_CREAT|O_TRUNC|O_RDWR, S_IRWXU)) == -1) {
        my_err("open", __LINE__);
    }

    if((ret = fcntl(fd, F_SETFL, O_APPEND)) < 0) {
        my_err("fcntl", __LINE__);
    }

    access_mode = ret & O_ACCMODE;
    if (access_mode == O_RDONLY) {
        printf("example_64 access mode: read only");
    } else if (access_mode == O_WRONLY) {
        printf("example_64 access mode: write only");
    } else if (access_mode == O_RDWR) {
        printf("example_64 access mode: read + write");
    }

    if (ret & O_APPEND) {
        printf(" ,append");
    }
    if (ret & O_NONBLOCK) {
        printf(" ,nonblock");
    }
    if (ret & O_SYNC) {
        printf(" ,sync");
    }
    printf("\n");

    return 0;
    
}

