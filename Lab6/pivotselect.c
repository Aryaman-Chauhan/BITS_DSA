#include "pivotselect.h"
#include "person.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

int medOfThree(PER* arr, int n){
    int left = arr[0]->height, right = arr[n - 1]->height;
    int mid = n / 2;
    mid = arr[mid]->height;
    if(left <= mid)
        if(mid <= right)
            return mid;
        else if(left <= right)
            return right;
        else
            return left;
    else
        if(left <= right)
            return left;
        else if(right <= mid)
            return mid;
        else
            return right;
}

int medOfMed(PER *arr, int n, int k){
    if (k == 0)
        return arr[0]->height;
    if (n <= 5){
        for (int i = 1; i < n; i++)
            for (int j = i-1; j >= 0; j--)
                if (arr[j]->height > arr[j+1]->height)
                    swap(arr, j, j+1);
                else
            break;
        return arr[k-1]->height;
    }
    // partition L into subsets of five elements each
    // (there will be n/5 subsets total).
    int numGroups;
    if (n % 5 == 0)
        numGroups = n/5;
    else
        numGroups = n/5 + 1;
    int medians[numGroups];
    for (int i = 0; i < numGroups; i++){
        medians[i] = medOfMed(arr + i*5, min(5, n - i*5), min(5, n - i*5)/2);
    }
    int M = medOfMed(medians, numGroups, (numGroups + 1) / 2);
    // Partition array into two halves, L1, {M} and L2, such that
    // L1 contains elements <= M, {M} contains one instance of M and L2
    // contains all elements > M
    int mInd;
    for (int i = 0; i < n; i++){
        if (arr[i]->height == M){
            mInd = i;
            break;
        }
    }
    int pInd = twoWay(arr, 0, n-1, mInd);
    if (k <= pInd)
        return medOfMed(arr, pInd, k);
    else if (k > pInd + 1)
        return medOfMed(arr + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return arr[pInd]->height;
}

int quickSel(PER* arr, int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = twoWay(arr, lo, hi, pivot);
    if (k <= pInd)
        return quickSel(arr, pInd, k);
    else if (k > pInd + 1)
        return quickSel(arr + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return arr[pInd]->height;
}

int randomSel(PER* arr, int n){
    struct timeval tv;
    int b = n - 1;
    int a = 0;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec * 1000000 + tv.tv_sec);
    int ind = (rand() % (b - a)) + a;
    return arr[ind]->height;
}