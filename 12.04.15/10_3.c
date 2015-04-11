#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *ar, const int N) {
    for (int *p = ar; p != ar+N; p++)
        printf("%d ", *p);
    printf("\n");
}

int main() {
    srand(time(0));
    const int N = 10;
    int ar[N];
    for (int *p = ar; p != ar+N; p++)
        *p = rand() % 51 - 25;
    print_array(ar, N);
    for (int *p = ar; p != ar+N; p++)
        if (*p < 0) *p = 0;
    print_array(ar, N);
    return 0;
}
