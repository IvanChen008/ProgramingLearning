/******************
 * time: 2019/03/08
 * author: IvanChan
 * name: fileStatus.c
 * purpose: learning to display file or file system status
 *  on the linux operate system.
 ******************/

/*************************
 * 在Shell下直接使用ls命令就可获取文件的属性，在程序中获取文件属性的方法却是stat/fstat
 * /lstat函数。
 * #include <sys/types.h><sys/stat.h><unistd.h>
 *      int stat(const char *file_name, struct stat *buf);
 *      int fstat(int filedes, struct stat *buf);
 *      int lstat(const char *file_name, struct stat *buf);
 * 3个函数的区别是：stat用于获取由参数file_name指定的文件的状态信息，保存在参数struct stat *buf中。
 * fstat与stat的区别在于fstat是通过文件描述符来指定文件的。lstat对于符号链接文件，lstat返回的是符号
 * 链接文件本身的状态信息，而stat返回的是符号链接指向的文件状态信息。
 * 
 * struct stat *buf 参数是一个用于保存文件状态信息的结构体。
 *
 * 
 * 
 * 
 *************************/
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    struct stat buf;
    
    if (argc != 2) {
        printf("Usage: my_stat <filenam> \n");
        exit(0);
    }
    
    if (stat(argv[1], &buf) == -1) {
        perror("stat: ");
        exit(1);
    }

    printf("device is: %ld \n", buf.st_dev);
    printf("inode is: %ld \n", buf.st_ino);
    printf("mode is: %d \n", buf.st_mode);
    printf("number of hard links is: %ld \n", buf.st_nlink);
    printf("user ID of owner is: %d \n", buf.st_uid);
    printf("group ID of owner is: %d \n", buf.st_gid);
    printf("device type (if inode device) is: %ld \n", buf.st_rdev);

    printf("total size, in bytes is: %ld \n", buf.st_size);
    printf("blocksize for filesystem I/O is: %ld \n", buf.st_blksize);
    printf("number of blocks allocated is: %ld \n", buf.st_blocks);

    printf("time of last access is: %s \n", ctime(&buf.st_atime));
    printf("time of last modification is is: %s \n", ctime(&buf.st_mtime));
    printf("time of last change is is: %s \n", ctime(&buf.st_ctime));

    return 0;
    
}