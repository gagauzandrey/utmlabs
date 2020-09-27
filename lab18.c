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
    printf("\n");
    printf("\t---------T A B L E---------\n\n");

    for (float x = startX; x < endX; x += dX) {
        if (x < 0 && b != 0) {
            F = a * (float)pow(x, 3) + b * (float)pow(x, 2);
        } else if (x > 0 && b == 0) {
            F = (x - a) / (x - c);
        } else {
            F = (x + 5) / (c * (x - 10));
        }

        if (!((long)floor(a) & (long)floor(b) & (long)floor(c))) {
            printf("|\tx = %.2f\t|\tF = %.0f\t|\n", x, F);
        } else {
            printf("|\tx = %.2f\t|\tF = %.2f\t|\n", x, F);
        }
    }
}

// && (x > 0 )