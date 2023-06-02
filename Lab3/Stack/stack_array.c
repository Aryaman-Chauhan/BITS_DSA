#include "element.h"
#include "stack.h"
#include "heap_usage.h"
#include <stdlib.h>

#define STACK_SIZE 1000
struct Stack{
    int top;
    Element data[STACK_SIZE];
};

Stack *newStack(){
    Stack *s = (Stack *)myalloc(sizeof(Stack));
    if (s != NULL){
        s->top = -1;
    }
    return s;
}

bool push(Stack *s, Element e){
    if(s->top == STACK_SIZE-1){
        return false;
    }
    s->data[++(s->top)] = e;
    return true;
}

Element * top(Stack * stack){
    if(isEmpty(stack))
        return NULL;
    return (stack->data+stack->top);
}

Element * pop(Stack * stack){
    if(isEmpty(stack))
        return NULL;
    Element * e = stack->data+ stack->top;
    stack->top--;
    return e;
}

bool isEmpty(Stack * stack){
    if(stack->top == -1)
        return true;
    return false;
}

void freeStack(Stack* stack){
    myfree(stack);
}