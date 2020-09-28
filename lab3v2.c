#include <stdio.h>

int main()
{
    const int MAX_ROWS = 4;
    const int MAX_COLUMNS = 5;
    int m[MAX_ROWS][MAX_COLUMNS];
    int i, j;
    
    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLUMNS; ++j) {
            printf("m[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
        printf("\n");
    }
 
  
    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = 0; j < MAX_COLUMNS; ++j) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int count;
    for (j = 0; j < MAX_COLUMNS; ++j) {
        for (i = 0; i < MAX_ROWS && m[i][j] != 0; ++i) {
            if (i == MAX_ROWS - 1) {
                count++;
            }
        }
    }
    printf("Кол-во столбов без 0: %d\n\n", count);

    int tmp;
    int sum[MAX_ROWS];
    int k;
    i = 0;
    for (k = 0; k < MAX_ROWS; ++k) {
        for (i, j = 0, sum[i] = 0; j < MAX_COLUMNS; ++j) {
            if (m[i][j] > 0 && m[i][j] % 2 == 0) {
                sum[i] += m[i][j];
            }
        }
        ++i;   
    }

    for (i = 0; i < MAX_ROWS; ++i) {
        printf("Сумма %d-ой строки: %d\n", i + 1, sum[i]);
    }
    printf("\n");
    
    int q;
    for (i = 0; i < MAX_ROWS; ++i) {
        for (j = i + 1; j < MAX_ROWS; ++j) {
            if (sum[i] > sum[j]) {
                for (k = 0; k < MAX_COLUMNS; ++k) {
                    tmp = m[i][k];
                    m[i][k] = m[j][k];
                    m[j][k] = tmp;
                }
            }
        }
            
    } 

    for (i = 0; i < MAX_ROWS; ++i) {
        for (k = 0; k < MAX_COLUMNS; ++k) {
            printf("%d\t", m[i][k]);
        }
        printf("\n");
    }
}
