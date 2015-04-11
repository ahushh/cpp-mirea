#include <stdio.h>

int main() {
    const int N = 5;
    int ar[N];
    for (int *p = ar; p != ar+N; p++)
        scanf("%d",p);
    int sum = 0;
    for (int *p = ar; p != ar+N; p++)
        sum += *p;
    printf("%d\n", sum);
    return 0;
}
