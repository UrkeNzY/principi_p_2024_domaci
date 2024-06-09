#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float sum = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        float br;
        scanf("%f", &br);
        sum += br * br;
    }

    printf("%.2f", sum);

    return 0;
}
