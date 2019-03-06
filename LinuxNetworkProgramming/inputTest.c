#include <stdio.h>
#include <stdlib.h>

/************** 
 * fetch the userinfo to save to the buf, the length of buf is len,
 * the data of user inputed end up with the sign of '\n' 
 **************/
int get_userinfo(char *buf, int len){
    int i;
    int c;
    if (buf == NULL){
        return -1;
    }

    i = 0;
    while ((c = getchar() != '\n') && (c != EOF) && (i < len - 2)) {
        buf[i++] = c;
    }
    buf[i++] = '\n';
    buf[i++] = '\0';
    return 0;
}

int main() {
    char *string = "USERNAME:";
    char input_buf[8];

    printf("%s", string);
    if (get_userinfo(input_buf, 32) < 0)
    {
        printf("error return from get_userinfo\n");
        exit(1);
    }
    printf("%s \n ", input_buf);
    printf("%s >>>\n ", input_buf);

}
