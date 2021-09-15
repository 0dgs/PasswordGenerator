#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
char * get_password(char * buf, size_t length){
    int i;
    
    for ( i = 0; i < length; ++i ){
        if ( rand() & 1 ){
            if ( rand() & 1 ){
                buf[i] = 'A' + rand() % ( 'Z' - 'A' + 1 );
            }
            else {
                buf[i] = 'a' + rand() % ( 'z' - 'a' + 1 );
            }
        }
        else {
            buf[i] = '0' + rand() % 10;
        }
    }
    buf[i] = '\0';
    
    return buf;
}
 
int main(void){
    char * buf;
    size_t length;
    
    srand(time(NULL));
    
    printf("Length: ");
    scanf("%u", &length);
    
    if ( ( buf = (char*)malloc(length + 1) ) == NULL ){
        perror("malloc");
        exit(1);
    }
    printf("Password: %s\n", get_password(buf, length));
    
    free(buf);
    exit(1);
}
