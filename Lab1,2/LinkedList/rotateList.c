#include "LinkedListFunctions.h"

int main(){
    printf("Let's create a list\n");
    LIST l1 = createNewList();
    int l;
    printf("Enter length of List: ");
    scanf("%d", &l);
    for(int i = 0; i < l; i++){
        printf("Enter element: ");
        int v;
        scanf("%d%c", &v);
        NODE n1 = createNewNode(v);
        insertLast(n1, l1);
    }
    printList(l1);
    printf("Rotation size: ");
    int k;
    scanf("%d", &k);
    rotate(k, l1);
    printList(l1);
    destroyList(l1);
}