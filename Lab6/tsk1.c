#include<stdio.h>
#include<stdlib.h>
#include "partition.h"
#include "person.h"
#include <string.h>

int main(){
    PER* arr = (PER*)malloc(1000* sizeof(PER));
    FILE* fptr;
    fptr = fopen("dat1000.csv","r");
    if(fptr == NULL){
        printf("Couldn't open file\n");
        return 0;
    }
    int i = 0;
    char* buf = (char*)malloc(1024* sizeof(char));
    while(fgets(buf, 1024, fptr)){
        char * token = strtok(buf, ",");
        PER temp = (PER)malloc(sizeof(person));
        temp->id = atoi(token);
        token = strtok(NULL, ",");
        temp->name= (char*)malloc(25*sizeof(char));
        strcpy(temp->name, token);
        token = strtok(NULL, ",");
        temp->age = atoi(token);
        token = strtok(NULL, ",");
        temp->weight = atoi(token);
        token = strtok(NULL, ",");
        temp->height = atoi(token);
        arr[i++] = temp;
    }
    free(buf);
    lomuto(arr, 0, 999, 986);
    for(int i = 0; i < 1000; i++){
        if(arr[i]->height<=196)
            printf("%d,%s,%d\n", arr[i]->id,arr[i]->name, arr[i]->height);
        free(arr[i]);
    }
    free(arr);
}