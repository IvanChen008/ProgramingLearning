/******************
 * time: 2019/03/11
 * name: rm_unlink_file.c
 * purpose: learning to remove or delete file 
 *  on the linux operate system.
 * author: ivanchan
 ******************/

/****************************
 * 修改文件名字或位置的函数：int rename(const char *oldpath, const char *newpath);
 * 操作成功返回0，发生错误返回-1。
 * param:
 *      const char * oldpath:指定要进行修改的文件名
 *      const char * newpath:修改成指定的文件名称
 *
 * 删除文件的函数：
 *      删除文件的函数-unlink
 *      删除目录的函数-rmdir       
 *      既能删除文件也能删除目录的函数-remove
 *  unlink函数删除一个文件，如果文件的链接数为0，且没有进程打开这个文件，则文件被删除
 *  占用的磁盘空间被释放。如果链接数为零但是被打开了，就等进程结束删除这个文件。利用
 *  这一点可以确保即使程序崩溃，它们创建的临时文件也不会遗留下来。
 *
 *  目录操作各种函数
 *  目录创建函数 int mkdir(const char *pathname, mode_t mode);
 *  目录删除函数 int rmdir(const char *pathname);
 *  获取当前目录函数 
 *      char * getcwd();
 *      char * get_current_dir_name(void);
 *      char * getwd(char *buf);
 *  设置工作目录函数    
 *      int chdir(const char *path);
 *      int fchdir(int fd);
 *  获取目录信息函数
 *      DIR * opendir(const char *name); 打开一个目录
 *      struct dirent *readdir(DIR *dir); 读取一个目录
 *      int closedir(DIR *dir); 关闭一个目录
 ****************************/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/******************
 *
 * 打开 path 的目录
 * 并输出目录的名字
 * 操作完成之后关闭文件
 *
 ******************/
int my_readdir(const char *path) {
    DIR     *dir;
    struct  dirent  *ptr;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return -1;
    }
    while((ptr = readdir(dir)) != NULL){
        printf("file name: %s \n", ptr->d_name);
    }
    closedir(dir);
    
    return 0;
}

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("listfile <target path> \n");
        exit(1);
    }
    if (my_readdir(argv[1]) < 0) {
        exit(1);
    }
    return 0;
}
