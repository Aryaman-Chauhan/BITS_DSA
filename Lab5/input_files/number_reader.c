#include "insert_ri.h"
#include <sys/time.h>

int main(void)
{
    // Reads the numbers stored in numbers100000.txt and stores them into an integer array
    FILE *fp = fopen("numbers100000.txt", "r");
    int numbers[100000];
    int num2[100000];
    struct timeval t1, t2;
    double time_taken1,time_taken2;
    int i = 0;
    while (fscanf(fp, "%d", &numbers[i]) != EOF)
    {
        i++;
    }
    fclose(fp);
    // Perform some operation on the numbers
    for (int i = 0; i < 100000; i++)
        num2[i] = numbers[i];
    gettimeofday(&t1, NULL);
    insertionSortI(numbers, 100000);
    gettimeofday(&t2, NULL);
    time_taken1 = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken1 = (time_taken1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    
    gettimeofday(&t1, NULL);
    insertionSortR(num2, 100000);
    gettimeofday(&t2, NULL);
    time_taken2 = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken2 = (time_taken2 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    
    // Example operation: Print the numbers stored in the array
    for (int i = 0; i < 100000; i++)
    {
        printf("%d : %d\n", numbers[i],num2[i]);
    }
    printf("Iterative Insertion Sort took %f seconds to execute\n", time_taken1);
    printf("Recursive Insertion Sort took %f seconds to execute\n", time_taken2);
}