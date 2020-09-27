#include <stdio.h>
#include <math.h>
#include <conio.h>

int main () {
	  float a, b , c , StartX, EndX, dX, x, F;

	  printf("Vvedite: ");
    printf("\ta = "); scanf("%f", &a);
    printf("\tb = "); scanf("%f", &b);
    printf("\tc = "); scanf("%f", &c);
    printf("\tX naci. = "); scanf("%f", &StartX);
    printf("\tX cone. = "); scanf("%f", &EndX);
    printf("\tdX = "); scanf("%f", &dX);

	    for ( x = StartX ; x <= EndX; x+=dX) {
		   if(x + 5 < 0 && c == 0)
	 	      F=(1 / a * x ) - b;
		    else if (x + 5 > 0 && c > 0)
		      F= (x - a) / x;
		    else 
		      F=(10 * x ) / (c- 4);
		    if (!(((long)floor(a) & (long)floor(b)) | ((long)floor(b) & (long)floor(c)))) {
            printf("x = %.2f\tF = %.0f\n", x, F);
        } else {
            printf("x = %.2f\tF = %.2f\n", x, F);
        }
    }
    return 0;
}       
     
