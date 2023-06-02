/*
The following code is supposed to create a 2D array of integers and floats.
The first array is of size 10 and the second array is of size 5.
The code is supposed to initialize the first array with the numbers 0 to 9
and the second array with the numbers 0.5 to 4.5.

The program has some compilation as well as runtime errors.
Fix the errors and run the program to make sure it works correctly.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    void **arr2D;
    int intArrSize = 10;
    int floatArrSize = 5;

    arr2D = (void **)malloc(2 * sizeof(void *));
    arr2D[0] = (int *)malloc(intArrSize * sizeof(int));
    arr2D[1] = (float *)malloc(floatArrSize * sizeof(float));

    for (int i = 0; i < intArrSize; i++)
    {
        int *a = arr2D[0];
        a += i;
        *a = i;
    }
    for (int i = 0; i < floatArrSize; i++)
    {
        float *f = arr2D[1];
        f += i;
        *f = i + 0.5;
    }
    // print arrays
    for (int i = 0; i < intArrSize; i++)
    {
        int *a = arr2D[0];
        a += i;
        printf("%d ", *(a));//Printing method was causing issue
    }
    printf("\n");
    for (int i = 0; i < floatArrSize; i++)
    {
        float *f = arr2D[1];
        f += i;
        printf("%f ", *(f)); // Printing in format *(float *)(arr +1 + i); was causing issue
    }
    printf("\n");
    return 0;
}