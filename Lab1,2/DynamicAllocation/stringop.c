#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addToStringEnd(char ** arr, char* s, int n){
    arr = realloc(arr, (n + 1) * sizeof(char*));
    (arr[n]) = s;
    return n+1;
}

int addToStringBeg(char ** arr, char* s, int n){
    arr = realloc(arr, (n + 1) * sizeof(char*));
    for(int i = n; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    (arr[0]) = s;
    return n+1;
}

int deleteAtInd(char** arr, int i, int n){
    free(arr[i]);
    for(int j = i; j < n-1; j++){
        arr[j] = arr[j+1];
    }
    arr = realloc(arr, (n-1)*sizeof(char*));
    return n-1;
}

int main(){
    int l;
    printf("Enter length of array: ");
    scanf("%d", &l);
    char** arr = calloc(l, sizeof(char*));
    if(arr == NULL){
        printf("Unable to allocate memory\n");
        return -1;
    }

    for(int i = 0; i < l; i++){
        printf("Enter length of string: ");
        int n;
        scanf("%d", &n);
        char* s = calloc(n, sizeof(char));
        if(s == NULL){
            printf("Unable to allocate memory\n");
            return -1;
        }
        printf("Enter string :");
        scanf("%s", s);
        arr[i] = s;
    }
    char ch;
    while(1){
        printf("Choose from the following options:\n");
        printf("1-Add string to end of the array\n");
        printf("2-Add string to beginning of the array\n");
        printf("3-Delete the element at index x of array\n");
        printf("4-Display length of array\n");
        printf("5- Display all elements in sequence\n");
        printf("Any other choice will close the program\n");
        scanf(" %c", &ch);
        switch(ch){
            case '1':{
                printf("Enter length of string: ");
                int n1;
                scanf("%d", &n1);
                char* s1 = calloc(n1, sizeof(char));
                if(s1 == NULL){
                    printf("Unable to allocate memory\n");
                    return -1;
                }
                printf("Enter strings :");
                scanf("%s", s1);
                l = addToStringEnd(arr, s1, l);
                break;}
            case '2':{
                printf("Enter length of string: ");
                int n2;
                scanf("%d", &n2);
                char* s2 = calloc(n2, sizeof(char));
                if(s2 == NULL){
                    printf("Unable to allocate memory\n");
                    return -1;
                }
                printf("Enter strings :");
                scanf("%s", s2);
                l = addToStringBeg(arr, s2, l);
                break;}
            case '3':{
                int i1;
                printf("Enter index: ");
                scanf("%d", &i1);
                l = deleteAtInd(arr,i1, l);
                break;}
            case '4':{
                printf("Length of array: %d\n", l);
                break;}
            case '5':{
                for(int i = 0; i < l; i++)
                    printf("%s\n", arr[i]);
                break;}
            default:{
                for(int i = 0; i < l; i++)
                    free(arr[i]);
                free(arr);
                return 0;}
        }
    }
}