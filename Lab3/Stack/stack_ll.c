#include "linked_list.h"
#include "heap_usage.h"
#include "stack.h"
#include<stdlib.h>

struct Stack{
    LIST l1;
};
typedef Stack *STACK;

Stack * newStack(){
    STACK st = (STACK)myalloc(sizeof(Stack));
    LIST lst = createNewList();
    st->l1 = lst;
    return st;
}

bool push(Stack *stack, Element element){
    LIST lst = stack->l1;
    NODE n1 = createNewNode(element);
    insertNodeIntoList(n1, lst);
    return true;
}

Element *top(Stack* stack){
    LIST lst = stack->l1;
    if(lst->head == NULL){
        return NULL;
    }
    return &(lst->head->data);
}

Element *pop(Stack *stack){
    LIST lst = stack->l1;
    if(lst->head == NULL){
        return NULL;
    }
    Element * e = &(lst->head->data);
    removeFirstNode(lst);
    return e;
}

bool isEmpty(Stack *stack){
    LIST lst = stack->l1;
    if(lst->count == 0)
        return true;
    return false;
}

void freeStack(Stack *stack){
    LIST lst = stack->l1;
    destroyList(lst);
    myfree(stack);
}