#include <stdio.h>

int main() {
    int k, n;
    printf("Input k and n: ");
    scanf("%d %d", &k, &n);
    for (int i = 1; i <= n-k; i++) {
        for (int j = i, l = 0; l < k; j++, l++) {
            printf("%d ",j);
        }
        printf("\n");
    }
}
