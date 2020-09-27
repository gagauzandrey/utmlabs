#include <stdio.h>
#include <math.h>

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

    for (float x = startX; x < endX; x += dX) {
        if (x + 5 < 0 && c == 0) {
            F = (1 / (a * x) - b);
            
        } else if (x + 5 > 0 && c != 0) {
            F = (x - a) / x;
        } else {
            F = (10 * x) / (c - 4);
        }
            printf("x = %.2f\tF = %.2f\n", x, F);
    }
    return 0;
}