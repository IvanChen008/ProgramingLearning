#include <stdio.h>
#include <stdlib.h>

/************** 
 * fetch the userinfo to save to the buf, the length of buf is len,
 * the data of user inputed end up with the sign of '\n' 
 **************/
int get_userinfo(char *buf, int len){
    int i;
    char c;
    int intc;
    if (buf == NULL){
        return -1;
    }

    i = 0;
    while ((c = getchar() != '\n') && (c != EOF) && (i < len - 2)) {
        printf("%c ", c);
        intc = c;
        printf("%d ", intc);
        buf[i++] = c;
    }
    buf[i++] = '\n';
    buf[i++] = '\0';
    return 0;
}

int main() {
    char *string = "USERNAME:";
    char input_buf[32];

    printf("%s", string);
    // if (get_userinfo(input_buf, 32) < 0)
    // {
    //     printf("error return from get_userinfo\n");
    //     exit(1);
    // }
    int i;
    char c;
    int intc;

    i = 0;
    while ((c = getchar() != '\n') && (c != EOF) && (i < 30)) {
        printf("%c ", c);
        intc = c;
        printf("%d ", intc);
        input_buf[i++] = c;
    }
    input_buf[i++] = '\n';
    input_buf[i++] = '\0';


    printf("%s \n ", input_buf);
    printf("%s >>>\n ", input_buf);

    return 0;
}
