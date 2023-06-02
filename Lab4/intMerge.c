#include "intMerge.h"
#include "intMergeAux.h"
#include "person.h"
#include "insertion.h"

void merge(PER A, int s, int mid, int e, char ch){
    PER C = (PER)malloc(sizeof(person) * (e - s + 1));
    if(ch == 'I' || ch == 'i')
        mergeAuxIter(A, s, mid, A, mid + 1, e, C, 0, e-s);
    else if(ch == 'R' || ch == 'r')
        mergeAuxRec(A, s, mid, A, mid + 1, e, C, 0, e-s);
    else 
        mergeByInsert(A, s, mid, mid + 1, e);
    for(int i = 0; i < e - s + 1; i++){
        A[s + i] = C[i];
    }
    free(C);
}

void mergeAuxIter (PER L1, int s1, int e1, PER L2, int s2, int e2, PER L3, int s3, int e3){
    int i,j,k;
    // Traverse both arrays
    i=s1; j=s2; k=s3;
    while (i <= e1 && j <= e2) {
        // Check if current element of first array is smaller
        // than current element of second array
        // If yes, store first array element and increment first
        // array index. Otherwise do same with second array
        if (L1[i].height < L2[j].height)
            L3[k++] = L1[i++];
        else
            L3[k++] = L2[j++];
    }
    // Store remaining elements of first array
    while (i <= e1)
        L3[k++] = L1[i++];
    // Store remaining elements of second array
    while (j <= e2)
        L3[k++] = L2[j++];
}

void mergeAuxRec(PER L1, int s1, int e1, PER L2, int s2, int e2, PER L3, int s3, int e3){
    if (L1[s1].height > L2[s2].height){
        L3[s3] = L2[s2];
        mergeAuxRec(L1, s1, e1, L2, s2 + 1, e2, L3, s3 + 1, e3);
    }
    else{
        L3[s3] = L1[s1];
        mergeAuxRec(L1, s1 + 1, e1, L2, s2, e2, L3, s3 + 1, e3);
    }
}

void mergeByInsert(PER L1, int s1, int e1, int s2, int e2){
    insertionSort(L1, s2, e2);
}