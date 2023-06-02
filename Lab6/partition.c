#include "person.h"
#include "partition.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int twoWay(PER * arr, int lo, int hi, int pInd){
    swap(arr, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = arr[lo]->height;
    while (lt < rt){
        for (; lt <= hi && arr[lt]->height <= pv; lt++);
        // Ls[j]<=pv for j in lo..lt-1
        for (; arr[rt]->height > pv; rt--);
        // Ls[j]>pv for j in rt+1..hi
        if (lt < rt){
            swap(arr, lt, rt);
            lt++;
            rt--;
        }
    }
    if (arr[lt]->height < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(arr, lo, pivPos);
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in 
    // pivPos+1..hi)
    return pivPos;
}

int threeWay(PER * arr, int lo, int hi, int pInd){
    swap(arr, pInd, hi);
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = arr[hi]->height;
    while (mid <= rt){
        if (arr[mid]->height < pv){
            swap(arr, lt, mid);
            lt++;
            mid++;
        }
        else if(arr[mid]->height>pv){
            swap(arr, mid, rt);
            rt--;
        }
        else{
            mid++;
        }
    }
    swap(arr, mid, hi);
    return mid;
}

int lomuto(PER * arr, int lo, int hi, int pInd){
    swap(arr, pInd, hi);
    int lt,rt,pv;
    lt = lo;
    rt = lo+1;
    pv = arr[hi]->height;
    while(rt<hi){
        if(arr[rt]->height<=pv){
            swap(arr, lt, rt);
            lt++;
            rt++;
        }
        else{
            rt++;
        }
    }
    if(arr[lt]->height<pv){
        swap(arr, hi, lt+1);
        pInd = lt+1;
    }
    else{
        swap(arr, hi, lt);
        pInd = lt;
    }
    return pInd;
}

void swap(PER * arr, int ind1, int ind2){
    PER temp = (PER)malloc(sizeof(person));
    temp->age = arr[ind1]->age;
    arr[ind1]->age = arr[ind2]->age;
    arr[ind2]->age = temp->age;
    temp->height = arr[ind1]->height;
    arr[ind1]->height = arr[ind2]->height;
    arr[ind2]->height = temp->height;
    temp->weight = arr[ind1]->weight;
    arr[ind1]->weight = arr[ind2]->weight;
    arr[ind2]->weight = temp->weight;
    temp->id = arr[ind1]->id;
    arr[ind1]->id = arr[ind2]->id;
    arr[ind2]->id = temp->id;
    char* nm = (char*)malloc(25 * sizeof(char));
    strcpy(nm,arr[ind1]->name);
    strcpy(arr[ind1]->name, arr[ind2]->name);
    strcpy(arr[ind2]->name,nm);
    free(temp);
    free(nm);
}