#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int ele;
    struct node* next;
} *NODE;

typedef struct linked_list{
    int count;
    NODE head;
} *LIST;

LIST createNewList();
NODE createNewNode(int value);
void insertAfter(int searchEle, NODE n1, LIST l1);
void printList(LIST l1);
void insertAt(int position, LIST l1, NODE n1);
void deleteAt(int position, LIST l1);
void insertFirst(NODE n1, LIST l1);
void insertLast(NODE n1, LIST l1);
void deleteFirst(NODE n1, LIST l1);
int search(int element, LIST l1);
void rotate(int k, LIST l1);
void destroyList(LIST l1);
void cyclicDestroy(LIST l1);
void invertList(LIST l1);
void hasCycle(LIST l1);