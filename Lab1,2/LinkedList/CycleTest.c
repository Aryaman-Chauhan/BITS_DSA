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
    int r = rand() % l;
    if(r==0){
        NODE temp = l1->head;
        while (temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = l1->head;
        printf("Loop created from tail to %d position\n", r);
    }
    else if(r!=(l-1) && l>1){
        int c = 0;
        NODE temp = l1->head;
        while(c<(r-1)){
            temp = temp->next;
            c++;
        }
        NODE temp1 = temp->next;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = temp1;
        printf("Loop created from tail to %d position\n", r);
    }
    printf("Testing algorithm to detect cycle: \n");
    hasCycle(l1);
    cyclicDestroy(l1);
}