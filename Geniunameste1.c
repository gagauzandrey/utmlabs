#include <stdio.h>
#include <math.h>

int main(){ 
    int a11, a12, a13, a21, a22, a23, a31, a32, a33, b1, b2, b3;
    float x1,x2,x3;
    int Dg,D1,D2,D3;
    printf("vvedite a11 , a12 , a13 , b1\n");
    scanf("%d%d%d%d" , &a11 , &a12 , &a13 , &b1 );
    printf("vvedite a21 , a22 , a23 , b2\n");
    scanf("%d%d%d%d" , &a21 , &a22 , &a23 , &b2 );
    printf("vvedite a31 , a32 , a33 , b3\n");
    scanf("%d%d%d%d" , &a31 , &a32 , &a33 , &b3 );
    printf("(%3d %3d %3d | %3d)\n(%3d %3d %3d | %3d)\n(%3d %3d %3d | %3d)\n" ,a11 , a12 , a13 , b1 ,a21 , a22 , a23 , b2 ,a31 , a32 , a33 , b3 );
    Dg = (a11 * a22 * a33)+(a21 * a32 * a13) + (a31 * a12 * a23) - (a13 * a22 * a31) - (a23 * a32 * a11)-(a33 * a12 * a21);
    if (Dg != 0){ 
        D1 = (b1 * a22 * a33) + (b2 * a32 * a13) + (b3 * a12 * a23) - (a13 * a22 * b3) - (a23 * a32 * b1) - (a33 * a12 * b2);
        D2 = (a11 * b2 * a33) + (a21 * b3 * a13) + (a31 * b1 * a23)-(a13 * b2 * a31)-(a23 * b3 *a11) - (a33 * b1 * a21); 
        D3 = (a11 * a22 * b3) + (a21 * a32 * b1) + (a31 * a12 * b2)-(b1 * a22 * a31) - (b2 * a32 * a11) - (b3 * a12 * a21);
        printf("D1 = %d\n", D1); 
        printf("D2 = %d\n", D2);
        printf("D3 = %d\n", D3);
        x1 = D1 / Dg ;
        x2 = D2 / Dg ;
        x3 = D3 / Dg ;
        printf("(x1, x2, x3) = (%.0f, %.0f, %.0f)" , x1 ,x2,x3 );
    }
    return 0;
}

    

