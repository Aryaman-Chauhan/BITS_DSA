#include "LinkedListFunctions.h"

LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}

NODE createNewNode(int value){
NODE myNode;
myNode = (NODE) malloc(sizeof(struct node));
myNode->ele=value;
myNode->next=NULL;
return myNode;
}

void insertAfter(int searchEle, NODE n1, LIST l1){
    if(l1->head==NULL){
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else{
        NODE temp = l1->head;
        NODE prev = temp;
        while(temp!=NULL){
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            printf("Element not found\n");
            return;
        }
        else{
            if(temp->next == NULL){
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else{
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}

void printList(LIST l1){
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp != NULL){
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
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

void deleteAt(int position, LIST l1){
    //List is empty
    if(l1 ->count == 0){
        printf("List is empty\n");
        return;
    }
    //Insert at beginning i.e., position = 0
    NODE temp = l1->head;
    if(position == 0){
        l1->head = temp->next;
        free(temp);
        l1->count--;
        return;
    }
    int i = 0;
    NODE nxt = temp->next;
    while(temp !=NULL){
        if(i==(position-1)){
            temp->next = nxt->next;
            free(nxt);
            l1->count--;
            return;
        }
    }
    printf("Invalid position\n");
}

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

void deleteFirst(NODE n1, LIST l1){
    //List is empty
    if(l1->count==0){
        printf("List is empty\n");
    }
    //List is not empty
    else{
        NODE temp = l1->head;
        l1->head = temp->next;
        free(temp);
        l1->count--;
    }
}

int search(int element, LIST l1){
    int r = -1;
    NODE temp = l1->head;
    while(temp->next!= NULL){
        r++;
        if(temp->ele == element)
            return r;
        temp = temp->next;
    }
    return r;
}

void rotate(int k, LIST l1){
    if(k>(l1->count) || l1->count==0){
        printf("Invalid k value, or empty list\n");
        return;
    }
    NODE ho = l1->head;
    NODE temp = l1->head;
    for (int i = 1; i < k; i++){
        temp = temp->next;
    }
    l1->head = temp->next;
    temp->next = NULL;
    temp = l1->head;
    while(temp->next!= NULL)
        temp = temp->next;
    temp->next = ho;
    printf("Successfully rotated by %d\n", k);
    return;
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
        free(temp2);
    }
    free(temp);
    free(l1);
}

void cyclicDestroy(LIST l1){
    if(l1->count==0){
        free(l1);
        return;
    }
    NODE temp = l1->head;
    int c = 1;
    while(c < l1->count){
        NODE temp2 = temp;
        temp = temp->next;
        free(temp2);
        c++;
    }
    free(temp);
    free(l1);
}

void invertList(LIST l1){
    if(l1->count<=1)
        return;
    NODE temp1 = l1->head;
    NODE temp2 = temp1->next;
    temp1->next = NULL;
    while(temp2->next!=NULL){
        NODE temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    temp2->next = temp1;
    l1->head = temp2;
}

void hasCycle(LIST l1){
    if(l1->count<=1){
        printf("No cycle detected.\n");
        return;
    }
    NODE temp1 = l1->head;
    NODE temp2 = temp1;
    while(temp1->next!=NULL || temp2->next->next!=NULL){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if(temp1==temp2){
            printf("Cycle detected at element = %d.\n", temp1->ele);
            return;
        }
    }
    printf("Cycle not detected.\n");
}