#include "linked_list.h"
#include "heap_usage.h"
#include<stdlib.h>
#include<stdio.h>

LIST createNewList(){
    LIST l1 = (LIST)myalloc(sizeof(linked_list));
    return l1;
}

NODE createNewNode(Element data){
    NODE n1 = (NODE)myalloc(sizeof(node));
    n1->data = data;
    n1->next = NULL;
    return n1;
}

void insertNodeIntoList(NODE n1, LIST l1){
    NODE temp = l1->head;
    l1->head = n1;
    n1->next = temp;
    l1->count++;
}

void removeFirstNode(LIST l1){
    if(l1->head == NULL){
        printf("Empty\n");
        return;
    }
    NODE temp = l1-> head;
    l1->head = temp->next;
    myfree(temp);
    l1->count--;
}

void insertNodeAtEnd( NODE n1, LIST l1){
    NODE temp = l1->head;
    if(temp==NULL){
        l1->head = n1;
        n1->next = NULL;
        return;
    }
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = n1;
    n1->next = NULL;
    l1->count++;
}

void destroyList(LIST l1){
    NODE n1 = l1->head;
    if(n1==NULL){
        myfree(l1);
        return;
    }
    while(n1->next!= NULL){
        NODE temp = n1->next;
        myfree(n1);
        n1 = temp;
    }
    myfree(n1);
    myfree(l1);
}