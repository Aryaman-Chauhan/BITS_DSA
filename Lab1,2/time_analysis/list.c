#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node nod;
typedef struct node{
    char *ID;
    double CGPA;
    nod * next;
} *NODE;

typedef struct linked_list ll;
typedef struct linked_list{
    int count;
    NODE head;
} *LIST;

void insertFirst(NODE n1, LIST l1){
    //List is empty
    if(l1->count == 0) {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    //When list is not empty
    else {
        n1->next = l1->head;
        l1->head = n1;
        l1->count++;
    }
}

void insertLast(NODE n1, LIST l1){
    if(l1->count==0){
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
        return;
    }
    NODE temp = l1->head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = n1;
    n1->next = NULL;
    l1->count++;
}

void insertAt(int position, LIST l1, NODE n1){
    if(l1->count==0 || l1->count < position){
        printf("Invalid insertion position\n");
        return;
    }
    else if(position==0){
        insertFirst(n1, l1);
        return;
    }
    NODE temp = l1->head;
    int c = 0;
    while(c < (position-1)){
        temp = temp->next;
        c++;
    }
    n1->next = temp->next;
    temp->next = n1;
    l1->count++;
}

void destroyList(LIST l1){
    if(l1->count==0){
        free(l1);
        return;
    }
    NODE temp = l1->head;
    while(temp->next!=NULL){
        NODE temp2 = temp;
        temp = temp->next;
        free(temp->ID);
        free(temp2);
    }
    free(temp->ID);
    free(temp);
    free(l1);
}

void printList(LIST l1,int a){
    NODE temp = l1->head;
    int c = 0;
    while(temp != NULL){
        printf("%s,%lf\n", temp->ID,temp->CGPA);
        temp = temp->next;
        c++;
        if(c==a)
            return;
    }
}

int main(){
    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    //READ AND STORE
    //Functions and operations considered in time evaluation start here
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if(fptr == NULL){
        printf("Couldn't open file\n");
        return 1;
    }
    LIST stud = (LIST)malloc(sizeof(ll));
    stud->count = 0;
    char buffer[100];
    const char s[2] = ",";
    int i = 0;
    while(fgets(buffer,1024,fptr)){
        NODE temp = (NODE)malloc(sizeof(nod));
        char * token = strtok(buffer, s);
        temp->ID = (char *)malloc(strlen(token) * sizeof(char));
        strcpy(temp->ID, token);
        token = strtok(NULL, s);
        temp->CGPA = atof(token);
        insertLast(temp, stud);
    }
    // Functions and operations after this operation aren't evaluated in time calculation
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printList(stud,10);
    printf("The tasks took %f seconds to execute\n", time_taken);
    destroyList(stud);
    fclose(fptr);
}