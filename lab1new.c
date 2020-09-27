#include <stdio.h>
#include <math.h>
#include <conio.h>

float getValue(float a, float b, float c, float x);

int main() {
    float   a, b, c;
    float   startX, endX, dX;
    float   F;

    printf("Enter:");
    printf("\ta = "); scanf("%f", &a);
    printf("\tb = "); scanf("%f", &b);
    printf("\tc = "); scanf("%f", &c);

    printf("\tX start = ", startX); scanf("%f", &startX);
    printf("\tX end = ", endX); scanf("%f", &endX);
    printf("\tdX = ", dX); scanf("%f", &dX);

    for (float x = startX; x <= endX; x += dX) {

        F = getValue(a, b, c, x);
        printf("x = %.2f\t", x);
        printf("F = %.2f\n", F);
    }
    return 0;
}






float getValue(float a, float b, float c, float x) {
    float res = 0.0;
    if (x + 5 < 0 && c == 0)
    {
        res = (1 / (a * x) - b);
    }
    else if (x + 5 > 0 && c != 0)
    {
        res = (x - a) / x;
    }
    else
    {
        res = (10 * x) / (c - 4);
    }
    return res;
}
