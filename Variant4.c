#include <stdio.h>
#include <math.h>
#include <conio.h>

float xxc (float a, float b , float c , float x ){
    float res = 0;
    if ( a >= 0 && b >= 0 && c >= 0){ 
        if( c > 0 && x != 0 ){
            res = (a * x) - c;
        } else 
        if( c < 0 && x == 0 ){
            res = ( x - a ) /  -c; 
        } else { 
            res = ( b * x ) / ( c - a );

        }
    }
    else
    {
    printf( " a , b , c menshe libo ravno nulu ");
    
    } 
    return res ;
}

int main (){
    float j;
    float a; float b ; float c ;
    float txnachalo ; float txend ; float dx ;
    printf ("vvedite znacenia a , b , c , kotorie menshe libo ravni nulu");
    printf("\ta = "); scanf("%f", &a);
    printf("\tb = "); scanf("%f", &b);
    printf("\tc = "); scanf("%f", &c);
    printf("\tX нач. = "); scanf("%f", &txnachalo);
    printf("\tX кон. = "); scanf("%f", &txend);
    printf("\tdX = "); scanf("%f", &dx);
    for (float x = txnachalo ; x <= txend; x += dx)
    {
    j = xxc( a , b , c , x );
    printf(" rezulitat = %f" , j );
    }
   
   return 0;
    
}