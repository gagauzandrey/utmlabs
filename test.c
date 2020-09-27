#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define ARRSIZE 5

int cmp_int(const void * a, const void * b) { 
    return *((int *)a) - *((int *)b);
}

int main() {
    int a = 1;
    int b = ++a;
    int c = a++;


    // int arr[ARRSIZE] = {5, -1, 99, 45, 4};
    int arr[ARRSIZE] = {};
    for (int i = 0; i < ARRSIZE; ++i) {
        arr[i] = rand() % 1000;
    }
    // int a = (&arr)[i] - arr;
    int sum = 0;
    for (int i = 0; i < ARRSIZE; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    qsort(arr, ARRSIZE, sizeof(arr[0]), cmp_int);
}