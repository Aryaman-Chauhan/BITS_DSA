#include "stack.h"
#include "heap_usage.h"
#include <stdio.h>
#include <sys/time.h>
Element itoe (int i);
int main()
{
    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    Stack *s = newStack();
    if(isEmpty(s))
        printf("Stack is empty\n");
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    push(s, itoe(1));
    int value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    push(s, itoe(2));
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    pop(s);
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s)?"true":"false");
    // printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s)?"true":"false");
    printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    freeStack(s);
    printf("Heap memory allocated: %ld\n", heapMemoryAllocated);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);
    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}