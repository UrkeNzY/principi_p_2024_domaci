#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            a[i][j] = x;
        }
    }

    int suma = 0;

    for(int i = 0; i < n; i++) {
        suma += a[i][i];
    }

    printf("%d", suma);

    return 0;
}
