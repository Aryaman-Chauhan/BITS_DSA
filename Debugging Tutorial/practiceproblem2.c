#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
    int i;
    float f;
    char s[100];
};
typedef struct Element Element;
struct node 
{
    Element data;
    struct node *next;
};
typedef struct node node;
typedef node *NODE;

struct linked_list
{
    NODE head;
    NODE tail;
    int count;
};

typedef struct linked_list linked_list;
typedef linked_list *LIST;

#include <stdlib.h>

LIST createNewList()
{
    LIST list = malloc(sizeof(linked_list));
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

NODE createNewNode(Element data)
{
    NODE nd = (NODE)malloc(sizeof(node));
    nd->data = data;
    nd->next = NULL;
    return nd;
}

void insertNodeIntoList(NODE node, LIST list)
{
    node->next = list->head;
    if(list->head == NULL)
        list->tail = node;
    list->head = node;
    list->count++;
}

void removeFirstNode(LIST list)
{
    NODE temp = list->head;
    list->head = list->head->next;
    if(list->head == NULL)
        list->tail = NULL;
    free(temp);
    list->count--;
}

void removeLastNode(LIST list)
{
    NODE temp = list->head;
    if(temp==list->tail){//This condition was non-existent,causing it to free a null, causing issue
        free(temp);
        list->count--;
        list->head = NULL;
        list->tail = NULL;
        return;
    }
    while(temp->next != list->tail)
        temp = temp->next;
    free(list->tail);
    list->tail = temp;
    list->tail->next = NULL;
    list->count--;
}

void insertNodeAtEnd(NODE node, LIST list)
{
    if(list->head == NULL)
        list->head = list->tail = node;
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
}

void destroyList(LIST list)
{
    while(list->head != NULL)
        removeFirstNode(list);
    free(list);
}

void printList(LIST list)
{
    NODE temp = list->head;
    while(temp != NULL)
    {
        printf("%d %f %s\n", temp->data.i, temp->data.f, temp->data.s);
        temp = temp->next;
    }
}

int main()
{
    LIST list = createNewList();
    Element e;
    e.i = 1;
    e.f = 1.1;
    strcpy(e.s, "one");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 2;
    e.f = 2.2;
    strcpy(e.s, "two");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 3;
    e.f = 3.3;
    strcpy(e.s, "three");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 4;
    e.f = 4.4;
    strcpy(e.s, "four");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 5;
    e.f = 5.5;
    strcpy(e.s, "five");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 6;
    e.f = 6.6;
    strcpy(e.s, "six");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 7;
    e.f = 7.7;
    strcpy(e.s, "seven");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 8;
    e.f = 8.8;
    strcpy(e.s, "eight");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 9;
    e.f = 9.9;
    strcpy(e.s, "nine");
    insertNodeIntoList(createNewNode(e), list);
    e.i = 10;
    e.f = 10.10;
    strcpy(e.s, "ten");
    insertNodeIntoList(createNewNode(e), list);
    printList(list);
    removeFirstNode(list);
    for (int i = 0; i < 9; i++)//i was being called 10 times even after 1 element removed in prev line
        removeLastNode(list);
    printList(list);
    destroyList(list);
    return 0;
}
