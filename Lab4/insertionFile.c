#include "insertion.h"
#include "person.h"
#include <string.h>

int main(int argc, char *argv[]){
    PER table;
    if(argc < 2){
        printf("Run your file with an argument of used csv file. eg.- ./insert.exe 1000\n");
        return 0;
    }
    int n = atoi(argv[1]);
    table = (PER)malloc(n * sizeof(person));
    int length = strlen(argv[1]) + 8;
    char *fname = (char *)malloc(length * sizeof(char));
    strcat(fname, "dat");
    strcat(fname, argv[1]);
    strcat(fname, ".csv\0");
    FILE * fptr = fopen(fname,"r");
    free(fname);
    if(fptr == NULL){
        printf("Couldn't read file\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        char buffer[1024];
        fscanf(fptr,"%[^\r]%*c",buffer); // Working for me if 10000
        // fgets(buffer, 1024, fptr); // Worked for 1000 but didn't for 10000
        char s[2] = ",";
        char * token = strtok(buffer,s);
        table[i].id = atoi(token);
        token = strtok(NULL, s);
        table[i].name = (char*)malloc(strlen(token)*sizeof(char));
        strcpy(table[i].name, token);
        // a.name = name; //This is pointing to the memory name, which when finally allocated last input, is shown to all user, as the person simply stores pointer and nothing else
        // printf("%s\n", a.name);
        // printf("%s\n", tab1->name);
        token = strtok(NULL, s);
        table[i].age = atoi(token);
        token = strtok(NULL, s);
        table[i].weight = atoi(token);
        token = strtok(NULL, s);
        table[i].height = atoi(token);
    }
    fclose(fptr);
    printf("Initial data: \n");
    for(int i = 0; i < n; i++){
        printf("%d %s %d %d %d\n", table[i].id, table[i].name, table[i].age, table[i].weight, table[i].height);
    }
    insertionSort(table, 0, n-1);
    printf("After sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d %s %d %d %d\n", table[i].id, table[i].name, table[i].age, table[i].weight, table[i].height);
    }
    for(int i = 0; i < n; i++){
        free(table[i].name);
    }
    free(table);
}