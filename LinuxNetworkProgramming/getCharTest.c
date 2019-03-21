#include<stdio.h>
#include<stdlib.h>
 
// void main()
// {
//     int c,j=0;
//     int a[10][10];
//     int n;
//     scanf("%d", &n);
//     getchar();
//     for (int i = 0; i<n; i++) {
//         j = 0;
//         while ((c = getchar()) != '\n') {
//             a[i][j++] = c;
//         }
//         a[i][j] = '\0';
//     }

//     printf ("shuzu: %d",a);
//     // return 0;
// }

int main(void)
{
        char ch;
        int num, len = 0;
        int intc;
        char a[8];
        num = 0;

        printf("input your strings:\n");

        // while ((ch = getchar() != '\n')) {
        //     printf("%c \n", ch);
        //     intc = ch;
        //     printf("%d  \n", intc);
        //     a[num++] = ch;
        // }

        while((ch = getchar()) != '\n'){
            printf("%c \n", ch);
            intc = ch;
            printf("intch: %c \n", intc);
            a[len] = ch;
            num++;
        }
        
        printf("\nThe string length is %d\n", num);
        printf("string Arr: %s", a);
        return 0;
}
// --------------------- 
// 作者：一束周末时光 
// 来源：CSDN 
// 原文：https://blog.csdn.net/misskissC/article/details/8802060 
// 版权声明：本文为博主原创文章，转载请附上博文链接！
