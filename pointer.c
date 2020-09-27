#include <stdio.h>

#define MAX_SIZE 5

int main() {
    int i, j;
    int array[MAX_SIZE];
    float sum = 0;
    float result = 1;
    int iMax, iMin;

    for (i = 0; i < MAX_SIZE; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("\n");
    for (i = 0; i < MAX_SIZE; i++) {
        // printf("array[%d] = %d\n", i, array[i]);
        printf("array[%d] = %d\n", i, array[i]);
    }
}