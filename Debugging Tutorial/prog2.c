#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
typedef node * NODE;

struct linked_list
{
    int count;
    NODE head;
    NODE tail; // Not required for stack. Required for Queue
};
typedef struct linked_list linked_list;
typedef linked_list * LIST;

LIST createNewList()
{
    LIST list = malloc(sizeof(linked_list));
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

NODE createNewNode(int data)
{
    NODE n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
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
    if(list->head == NULL)
        return;
    else if(list->head == list->tail)
    {
        free(list->head);
        list->head = list->tail = NULL;
        list->count--;
        return;
    }
    NODE temp = list->head;
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

void removeNode(int data, LIST list)
{
        NODE prev = NULL;
        NODE pointer = list->head;
        /* Iterate to find pointer */
        while( (pointer != NULL) && (pointer->data != data ))
        {
                prev = pointer;
                pointer = pointer -> next;
        }
        if(pointer==NULL)
        {
                printf("Element %d is not present in the list\n",data);
                return;
        }
        
        /* Set previous pointer to next pointer */
        prev->next = pointer->next;            
        free(pointer);
       
        return;
}

void print(LIST list)
{
    NODE temp = list->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    LIST list = createNewList();
    removeNode(5, list);
    insertNodeIntoList(createNewNode(5), list);
    insertNodeIntoList(createNewNode(3), list);
    insertNodeIntoList(createNewNode(2), list);
    insertNodeIntoList(createNewNode(9), list);
    print(list);

    removeNode(3, list);
    removeNode(6, list);
    removeNode(5, list);
    removeNode(9, list);
    removeNode(2, list);
    removeNode(6, list);

    print(list);
    destroyList(list);

    return 0;
}