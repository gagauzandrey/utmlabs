#include <stdio.h> 

const int MAX_ELEMENTS = 8;

int main(int argc, char* argv[]) {
    float   m[MAX_ELEMENTS];
    float   sum = 0;
    float   result = 1;
    int     iMax, iMin;

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("m[%d] = ", i);
        scanf("%f", &m[i]);
    }

    iMin = iMax = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (m[i] < 0) sum += m[i];

        if (m[i] > m[iMax]) iMax = i;
        if (m[i] < m[iMin]) iMin = i;
    }

    for (int i = ((iMax < iMin) ? iMax : iMin); i <= ((iMax > iMin) ? iMax : iMin); result *= m[i++]);

    printf("\nSum of negative nums = %.2f\n", sum);
    printf("Result = %.2f\n\n", result);

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        for (int j = i + 1; j < MAX_ELEMENTS; j++) {
            if (m[i] > m[j]) {
                result = m[i];
                m[i] = m[j];
                m[j] = result;
            }
        }
    }

    printf("Sorted array:\n");

    for (int i = 0; i < MAX_ELEMENTS; printf("%.f ", m[i++]));
    return 0;

}