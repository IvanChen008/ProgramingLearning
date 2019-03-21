/*********************
 * time: 2019/03/05
 * author: IvanChan
 * name: inputCheck.c
 * purpose: 对输入的参数进行检查是一个良好的习惯，它可以有效的避免可能存在的溢出漏洞。
 * 编程中应该注意对输入数据的类型、输入数据的长度进行合法性检查。特别是指针参数，
 * 必须检查其是否为空指针，它所指的空间是否大于缓冲区的空间。
 *********************/
#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *strDest, const char * strSrc) {
    char *p_return = strDest;

    // check whether the pointer of arguments is NULL
    if (strDest == NULL || strSrc == NULL) {
        fprintf(stderr, "NULL Point");
        return NULL;        
    }
    
    while((*strDest++ = *strSrc++) != '\0')
        ;
    return p_return;
}

int main() {
    char string1[32];
    char string2[32];
    int c;
    int i = 0;
    
    printf("please input your string:");

    // check the length of input string 
    while(((c = getchar()) != '\n') && (c != EOF) && (i < 32)){
        string2[i] = c;
        i++;
    }
    string2[i] = '\0';

    // check whether the returned value is legal.
    if (my_strcpy(string1, string2) == NULL) {
        fprintf(stderr, "return from my_strcpy");
        exit(1);
    }

    printf("string1: %s\n", string1);
    printf("string2: %s\n", string2);
    
    return 0;
}
