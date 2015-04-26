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
    ar[0] = rand()%10+2;
    for (int i = 1; i < N; i++)
        ar[i] = rand()%ar[i-1]+ar[i-1];
    print_array(ar, N);

    int x = ar[ rand()%N ];
    printf("Looking for %d\n", x);

    int i = 0, j = N-1;
    while (i < j) {
        int m = (i+j)/2;
        if (x <= ar[m])
            j = m;
        else
            i = m + 1;
    }
    if (ar[j] == x)
        printf("Found at %d\n", j);
    else
        printf("Not found");
    return 0;
}
