#include <stdlib.h>
#include <stdio.h>
#define ADDITIONAL_MEMORY sizeof(int)
void * myalloc(size_t size);
void myfree(void * ptr);