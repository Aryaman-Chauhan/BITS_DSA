#include <stdio.h>

int main(){
    FILE *fptr1, *fptr2;
    fptr1 = fopen("text1.txt", "r");
    fptr2 = fopen("text2.txt", "a");

    if(fptr1 == NULL || fptr2== NULL){
        printf("File couldn't open\n");
        return -1;
    }
    char buffer[1024];
    while(fgets(buffer, 1024, fptr1)){
        fprintf(fptr2, "%s", buffer);
    }
    fclose(fptr1);
    fclose(fptr2);
    fptr1 = fopen("text1.txt", "w");
    fclose(fptr1);
}