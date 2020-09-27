#include <stdio.h>

int main(void)
{
   /*  char var;
    printf("Enter something: ");
    while ((var = getchar()) != EOF) {
        putchar(var);
    } */


  /*   a = 2; b = 3;
    a = a + b;
    b = a - b;
    a = a - b; */
    /* a = 1; b = 0;
    c = a++ + b++;
    return 0; */

    int a = 102, c;
    c = a % 10 + a / 10 % 10 + a /100;
    printf("%d", c);
    return 0;
}
