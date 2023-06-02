#include <stdio.h>

int main(){
    int num;
    FILE *fptr;
    // printf("reading from: %s\n", __FILE__);
    fptr = fopen(__FILE__, "r");
    if(fptr == NULL){
        printf("Error in opening file");
        return -1;
    }
    char buffer[1024];
    while(fgets(buffer, 1024, fptr)){
        printf("%s", buffer);
    }
    fclose(fptr);
}