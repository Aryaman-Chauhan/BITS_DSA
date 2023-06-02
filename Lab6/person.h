#ifndef PERSON_H
#define PERSON_H
struct person{
    int id;
    char* name;
    int age;
    int height;
    int weight;
};
typedef struct person person;
typedef struct person * PER; 
#endif