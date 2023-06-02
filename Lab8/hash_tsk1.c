#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

int main(){
    FILE * fptr;
    fptr = fopen("t1_data.txt","r");
    char buf[50];
    fgets(buf,50,fptr); 
    int N = atoi(buf);
    int col = 0;
    int i = 0;
    STU hstab = (STU)malloc(2*N*sizeof(student));
    for(int j = 0; j < 2 * N; j++){
        hstab[i].next = NULL;
        hstab[i].prev = NULL;
        for(int k = 0; k < 50; k++)
            hstab[i].name[k] = '\0';
    }
    while(fgets(buf,50,fptr)){
        char * token = strtok(buf,",");
        student temp;
        temp.prev = NULL;
        temp.next = NULL;
        temp.ID = atoi(token);
        token = strtok(NULL,",");
        strcpy(temp.name,token);
        i = temp.ID%N;
        if(hstab[i].next != NULL || hstab[i].name[0] != '\0'){
            col++;
            STU temp1 = hstab[i].next;
            STU pretemp = &(hstab[i]);
            while (temp1!=NULL)
            {
                pretemp = temp1;
                temp1 = temp1->next;
            }
            temp.prev = pretemp;
            temp1 = &temp;
        }
        else{
            hstab[i] = temp;
        }
    }
    printf("Collisions are %d\n",col);
}