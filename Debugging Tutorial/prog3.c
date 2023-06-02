#include <stdio.h>

int searchInsert(int* A, int n1, int B) 
{
    int high = n1-1;
    int low = 0;
    int mid;

    while(low <= high)
    {
        mid = (low + (high - low) / 2);
        if(A[mid] == B)
            return mid;
        else if(A[mid] > B)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return mid;
}

int main(void)
{
    int A[4] = {1,3,5,6};
    int B = 2;
    int n1 = 4;
    int result = searchInsert(A, n1, B);
    printf("%d ", result);
    return 0;
}