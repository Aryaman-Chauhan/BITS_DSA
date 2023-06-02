#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int ind1, int ind2){
    int i = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = i;
}

int twoWay(int * arr, int lo, int hi, int pInd){
    swap(arr, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = arr[lo];
    while (lt < rt){
        for (; lt <= hi && arr[lt] <= pv; lt++);
        // Ls[j]<=pv for j in lo..lt-1
        for (; arr[rt]> pv; rt--);
        // Ls[j]>pv for j in rt+1..hi
        if (lt < rt){
            swap(arr, lt, rt);
            lt++;
            rt--;
        }
    }
    if (arr[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(arr, lo, pivPos);
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in 
    // pivPos+1..hi)
    return pivPos;
}

int main(){
    printf("Enter length of input: ");
    int l;
    char ch;
    scanf("%d%c", &l, &ch);
    char * io = (char*)malloc((l+1)*sizeof(char));
    scanf("%s", io);
    int n = atoi(io);
    int * arr = (int *)malloc(l * sizeof(int));
    for(int i = 0; i < l; i++){
        arr[i] = n%10;
        n/=10;
    }
    twoWay(arr, 0, l-1, 0);
    for(int i = 0; i< l; i++)
        printf("%d", arr[i]);
    printf("\n");
    free(io);
    free(arr);
}