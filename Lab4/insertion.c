#include "insertion.h"
#include "person.h"

void insertionSort(PER p1, int st, int en){
    for(int i = st; i < en; i++){
        int j = i;
        while(j>=0){
            if(p1[j+1].height<p1[j].height){
                struct person temp = p1[j];
                // printf("%d %s %d %d %d\n", temp.id, temp.name, temp.age, temp.height, temp.weight);
                p1[j] = p1[j+1];
                p1[j+1] = temp;
            }
            else
                break;
            j--;
        }
    }
}