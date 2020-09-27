#include <stdio.h>
#include <math.h>

#define MAX_ELEMENTS 9

int main(int argc, char* argv[]) {
    float   m[MAX_ELEMENTS];
    float   sum = 0;
    float result;
    int   iMax;
    int   firstElement, secondElement;
    int   i;

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("m[%d] = ", i);
        scanf("%f", &m[i]);
    }

    iMax = 0;

    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (fabs(m[i]) > fabs(m[iMax])) iMax = i;
    }

    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (m[i] > 0) {
            firstElement = i;
            break;
        }
    }
    for (i = firstElement + 1; i < MAX_ELEMENTS; i++) {
        if (m[i] > 0) {
            secondElement = i;
            break;
        }
    }

    for (i = firstElement + 1; i < secondElement; i++) {
        sum += m[i];
    }

   /*  for(i = 0; i < MAX_ELEMENTS; i++) {
	    if(m[i] == 0) {  
            for(int j = i; j < MAX_ELEMENTS - 1; j++) {
                m[j] = m[j + 1]; 
                m[MAX_ELEMENTS - 1] = 0;
            }
        }
    } */

/*     float sortedArr[MAX_ELEMENTS];
    int k = 0;
    int j = MAX_ELEMENTS / 2;
    for (i = 0; i < MAX_ELEMENTS; ++i) {
        if (m[i] == 0) {
            sortedArr[j] = m[i];
            j++; 
        } else {
            sortedArr[k] = m[i];
            k++;
        }
    } */
        int j;
        float sortedArr[MAX_ELEMENTS];
        for(i = 0; i < MAX_ELEMENTS; ++i) {
             if(m[i] != 0) {
                sortedArr[j] = m[i];
                j++;
            }
        }

        for(i = 0; i < MAX_ELEMENTS; ++i) {
            if(m[i] == 0) {
                sortedArr[j] = m[i];
                j++;
            }
        }
    printf("Максимальный элемент по модулю: %.1f\n", m[iMax]);
    printf("Сумму элементов между первыми двумя положительными элементами: %.1f\n", sum);
    for (i = 0; i < MAX_ELEMENTS; i++) {
        printf("%.2f    ", sortedArr[i]);
    }

    return 0;
}

/* if (i % 2 == 0) {

} else {
    
} */