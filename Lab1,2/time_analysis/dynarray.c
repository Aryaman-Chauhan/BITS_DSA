#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    char *ID;
    double CGPA;
};
typedef struct student *STU;

void addToPos(STU * stud, char* id, double cg, int pos){
    STU temp = (STU)malloc(sizeof(struct student));
    temp->CGPA = cg;
    temp->ID = (char *)malloc(14 * sizeof(char));
    strcpy(temp->ID, id);
    int l = 10010 - pos;
    int i = pos - 1;
    STU temp1 = stud[i];
    STU temp2 = stud[i + 1];
    for (int j = 0; j < l; j++,i++)
    {
        stud[i + 1] = temp1;
        temp1 = temp2;
    }
    if(pos!=10010){
        stud[i + 1] = temp2;
    }
    stud[pos - 1] = temp;
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
    STU * stud = (STU*)malloc(10000* sizeof(STU));
    char buffer[100];
    const char s[2] = ",";
    int i = 0;
    while(fgets(buffer,1024,fptr)){
        char * token = strtok(buffer, s);
        STU temp = (STU)malloc(sizeof(struct student));
        temp->ID = (char *)malloc(strlen(token) * sizeof(char));
        strcpy(temp->ID, token);
        token = strtok(NULL, s);
        temp->CGPA = atof(token);
        stud[i++] = temp;
    }
    // Functions and operations after this operation aren't evaluated in time calculation
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    for (int j = 0; j < 100;j++){
        printf("%s,%lf\n", stud[j]->ID, stud[j]->CGPA);
    }
    printf("The reading and storing took %f seconds to execute\n", time_taken);
    // Storing 10 data at user specified location
    printf("Now input 10 data values, as well as the position of insertion:\n");
    printf("NOTE: Position starts from 1\n");
    char **ids = (char **)malloc(10 * sizeof(char *));
    double cgs[10];
    int position[10];
    for (int i = 0; i < 10;i++){
        printf("ID: ");
        char * idprox = (char *)malloc(14 * sizeof(char));
        scanf("%s[^\n]", idprox);
        ids[i] = idprox;
        printf("CG: ");
        char buf;
        scanf("%lf%c", &cgs[i], buf);
        printf("Position: ");
        scanf("%d%c", &position[i], buf);
    }
    gettimeofday(&t1, NULL);
    //Self designed realloc to ensure safety
    STU* stud1 = (STU*)malloc(10010 * sizeof(STU));
    for (int j = 0; j < 10000;j++){
        stud1[j] = stud[j];
    }
    for (int j = 10000; j < 10010;j++){
        stud[i] = (STU)malloc(sizeof(struct student));
    }
        free(stud);
    for (int j = 0; j < 10; j++){
        addToPos(stud1, ids[j], cgs[j], position[j]);
    }
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The extra storing took %f seconds to execute\n", time_taken);
    printf("At pos 1 %s has CG: %lf\n", stud1[0]->ID, stud1[0]->CGPA);
    for (i = 0; i < 10010; i++)
    {
        free(stud[i]);
    }
    free(stud);
    fclose(fptr);
}