#include "insertion.h"
#include "person.h"

int main(){
    PER table;
    printf("Enter no. of data members: ");
    int n;
    char buf;
    scanf("%d%c",&n, &buf);
    table = (PER)malloc(n * sizeof(struct person));
    printf("Enter data of each member one by one: \n");
    for(int i = 0; i < n; i++){
        printf("Enter details of member %d:\n", (i+1));
        printf("ID: ");
        scanf("%d%c",&table[i].id,&buf);
        printf("Name: ");
        char name[10];
        scanf("%s[^\n]",name);
        printf("Age: ");
        scanf("%d%c", &table[i].age, &buf);
        printf("Height: ");
        scanf("%d%c", &table[i].height, &buf);
        printf("Weight: ");
        scanf("%d%c", &table[i].weight, &buf);
        table[i].name = (char*)malloc(strlen(name)*sizeof(char));
        strcpy(table[i].name, name);
        // a.name = name; //This is pointing to the memory name, which when finally allocated last input, is shown to all user, as the person simply stores pointer and nothing else
        // printf("%s\n", a.name);
        // printf("%s\n", tab1->name);
    }
    printf("Initial data: \n");
    for(int i = 0; i < n; i++){
        printf("%d %s %d %d %d\n", table[i].id, table[i].name, table[i].age, table[i].height, table[i].weight);
    }
    insertionSort(table, 0, n-1);
    printf("After sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d %s %d %d %d\n", table[i].id, table[i].name, table[i].age, table[i].height, table[i].weight);
    }
    for(int i = 0; i < n; i++){
        free(table[i].name);
    }
    free(table);
}