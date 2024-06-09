#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int sum = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int br;
        scanf("%d", &br);
        sum += br * br;
    }

    printf("%d", sum);

    return 0;
}
