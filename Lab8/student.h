#ifndef STUDENT_H
#define STUDENT_H
typedef struct student * STU;
struct student{
    STU prev;
    long long int ID;
    char name[30];
    STU next;
};
typedef struct student student;
#endif