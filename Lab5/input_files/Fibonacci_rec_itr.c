#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>

long recFib(int n){
    if(n==1 || n==2){
        return 1;
    }
    return recFib(n - 1) + recFib(n - 2);
}

long iterFib(int n){
    long s = 0, a = 0, b = 1;
    for (int i = 0; i < n; i++){
        s = a + b;
        b = a;
        a = s;
    }
    return a;
}

int main(){
    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    printf("%ld\n",iterFib(30));
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative Fibonacci took %f seconds to execute\n", time_taken);
    gettimeofday(&t1, NULL);
    printf("%ld\n",recFib(30));
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Recursive Fibonacci took %f seconds to execute\n", time_taken);
    return 0;
}