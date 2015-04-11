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
       *p = rand()%10;
   print_array(ar, N);
   int maxi = 0;
   for (int i = 1; i < N; i++)
       if (*(ar+i) >= *(ar+maxi))
           maxi = i;
   printf("%d\n", maxi);
   return 0;
}
