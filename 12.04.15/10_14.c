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
       *p = rand()%20-10;
   print_array(ar, N);
   int neg = 0, pos = 0;
   for (int *p = ar; p != ar+N; p++)
       if (*p > 0)
           pos++;
       else 
           neg++;
   printf("%f\n", (double)neg/pos);
   return 0;
}
