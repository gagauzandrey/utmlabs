#include <stdio.h>
#include <math.h>

int main(){
    int n,m,i,j; 
    int x1 , x2 , x3;
    printf("stroki/stolbtsi =");
    scanf("%d%d", &n, &m);
    int a[n][m];
    for ( i = 0; i < n; i++) { 
        for ( j = 0 ; i < m ; j++ ) {
            scanf("%d" , &a[i][j] );
        }
    }
    return 0;
}