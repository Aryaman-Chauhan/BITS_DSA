/*
Here is a program that attempts to sort an array of items by key.
The program is supposed to sort the array in ascending order.
However, the program does not work correctly.
Debug the program so that it works correctly.
*/

#include <stdio.h>

typedef struct
{
    char data[4096];
    int key;
} item;

item array[] = {
    {"Bill", 62},
    {"Hill", 60},
    {"Barcak", 42},
    {"Dicky", 105},
    {"W.", 1},
};

void sort(item *a, int n)
{
    int s;
    int an = n;
    for (int i = 0; i < an && s != 0; i++)// Here, i was compared to n, which changed each iteration, causing it to be unable to execute last iteration
    {
        s = 0;
        for (int j = 0; j < n - 1; j++)//Was being run to n, better optimisation to run till n-1
        {
            if (a[j].key > a[j + 1].key)
            {
                item t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                s++;
            }
        }
        n--;
    }
}

int main()
{

    sort(array, 5);
    printf("Sorted array:\n");
    for (int i = 0; i < 5; i++)
        printf("%d: %s %d\n", i + 1, array[i].data, array[i].key);

    return (0);
}