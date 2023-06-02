#ifndef INTMERGEAUX_H
#define INTMERGEAUX_H
#include "person.h"
void mergeAuxIter(PER A, int s1, int e1, PER B, int s2, int e2, PER C, int s3, int e3);
void mergeAuxRec(PER A, int s1, int e1, PER B, int s2, int e2, PER C, int s3, int e3);
void mergeByInsert(PER L1, int s1, int e1, int s2, int e2);
#endif