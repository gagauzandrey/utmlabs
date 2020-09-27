#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float a, b, c;
    float xstart, endx, dX;
    float F;

    printf("Введите:");
    printf("a = ");
    scanf("%f", &a);
    printf("\tb = ");
    scanf("%f", &b);
    printf("\tc = ");
    scanf("%f", &c);
    printf("\txstart. = ");
    scanf("%f", &xstart);
    printf("\tendx. = ");
    scanf("%f", &endx);
    printf("\tdX = ");
    scanf("%f", &dX);

    for (float x = xstart; x <= endx; x += dX) {
        if (c + b < 0 && a != 0)
            {
                F = (a * pow(cos(x), 2) + c) / (pow(b, 2) - x);
            }
        else if (c + b > 0 && a == 0) {
            F = ((a*x) - log(b*x)) / (pow ( b,2 ) - (c*x));
        }
        else

        F = (3 * sin(x) + 4 * log(2*x)) / (pow (a,2) + c +(b*x));
             if (!(((long)floor(a) | (long)floor(b)) & ((long)floor(a) | (long)floor(c))))
             printf("x = %.2f\tF = %.0f\n", x, F);
        else
            printf("x = %.2f\tF = %.2f\n", x, F);
    }
    return 0;
}