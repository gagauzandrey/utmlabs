#include <stdio.h>

#define MAX_SIZE 8

int main() {
    float m[MAX_SIZE];
    int iMax;
    int i, j;

    for (i = 0; i < MAX_SIZE; ++i) {
        printf("m[%d] = ", i);
        scanf("%f", &m[i]);
    }

    float result = 1;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (m[i] < 0) {
             result *= m[i]; 
        }
    }

    iMax = 0;
    for (i = 0; i < MAX_SIZE; ++i) {
        if (m[i] > m[iMax]) {
            iMax = i;
        }
    }

    float sum = 0;
    for (i = 0; i < iMax; ++i) {
        sum += m[i];
    }
    
    printf("Произведение отрицательных элементов: %.2f\n", result);
    printf("Сумма элементов до максимального элемента: %.2f\n\n", sum);

    for (i = 0; i < MAX_SIZE/2; ++i) {
        result = m[i]; 
        m[i] = m[MAX_SIZE-1-i]; 
        m[MAX_SIZE-1-i] = result;
    }        

    printf("Отсортированный массив:\n");

    for (i = 0; i < MAX_SIZE; ++i) {
        printf("%.2f ", m[i]);
    }

    return 0;
}