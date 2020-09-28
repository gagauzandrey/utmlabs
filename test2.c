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

    int count;
    for (j = 0; j < MAX_COLUMNS; ++j) {
        for (i = 0; i < MAX_ROWS && m[i][j] != 0; ++i) {
            if (i == MAX_ROWS - 1) {
                count++;
            }
        }
    }
    printf("Кол-во столбов без 0: %d\n", count);

    int k1[MAX_COLUMNS];
    for (i = 0, j = 0; j < MAX_COLUMNS; ++j) {
        k1[j] = m[i][j];
    }
    ++i;

    for (j = 0; j < MAX_COLUMNS; ++j) {
        printf("%d", k1[j]);     
    } 
    printf("\n");

    int k2[MAX_COLUMNS];
    for (i, j = 0; j < MAX_COLUMNS; ++j) {
        k2[j] = m[i][j];
    }
    ++i;

    for (j = 0; j < MAX_COLUMNS; ++j) {
        printf("%d", k2[j]);     
    } 
    printf("\n");

    int k3[MAX_COLUMNS];
    for (i, j = 0; j < MAX_COLUMNS; ++j) {
        k3[j] = m[i][j];
    }
    ++i;

    for (j = 0; j < MAX_COLUMNS; ++j) {
        printf("%d", k3[j]);     
    } 
    printf("\n");

    int k4[MAX_COLUMNS];
    for (i, j = 0; j < MAX_COLUMNS; ++j) {
        k4[j] = m[i][j];
    }
    ++i;

    for (j = 0; j < MAX_COLUMNS; ++j) {
        printf("%d", k4[j]);     
    } 
    printf("\n");
}
