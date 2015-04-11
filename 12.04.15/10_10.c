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
   int a = 1, b = 4;
   int ar[N];
   for (int *p = ar; p != ar+N; p++)
       *p = rand()%10;
   print_array(ar, N);
   int product = 1;
   for (int *p = ar; p != ar+N; p++)
       if (*p >= a && *p <= b)
           product *= *p;
   printf("%d\n", product);
   return 0;
}
