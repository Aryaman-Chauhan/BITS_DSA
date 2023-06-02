#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "intMerge.h"
#include "intMergeAux.h"
#include "person.h"

void mergeSort(PER A, int st, int en, char ch){
    if (en - st < 1)
        return;
    int mid = (st + en) / 2; // mid is the floor of (st+en)/2
    mergeSort(A, st, mid, ch); // sort the first half
    mergeSort(A, mid + 1, en, ch); // sort the second half
    merge(A, st, mid, en, ch); // merge the two halves
}
// Postcondition: forall j: st<=j<en-1 --> A[j]<=A[j+1]

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
    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    mergeSort(table, 0, 999, 'I');
    gettimeofday(&t2,NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    for (int i = 0; i < n; i++){
        printf("%d %s %d %d %d\n", table[i].id, table[i].name, table[i].age, table[i].weight, table[i].height);
    }
    for(int i = 0; i < n; i++){
        free(table[i].name);
    }
    free(table);
    printf("Time taken to sort %f\n", time_taken);
}