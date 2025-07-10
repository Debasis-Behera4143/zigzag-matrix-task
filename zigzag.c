#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i*i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}

int compute_zigzag_sum(int** matrix, int n) {
    int sum = 0, val;
    for (int d = 0; d <= 2 * (n - 1); d++) {
        for (int i = 0; i <= d; i++) {
            int r = (d % 2 == 0) ? i : d - i;
            int c = (d % 2 == 0) ? d - i : i;
            if (r < n && c < n) {
                val = *(*(matrix + r) + c);
                sum += isPrime(val) ? -val : val;
            }
        }
    }
    return sum;
}

int main() {
    int n, **matrix;
    printf("Enter matrix size (n): ");
    scanf("%d", &n);

    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        *(matrix + i) = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n * n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", (*(matrix + i) + j));

    printf("Final Zigzag Sum: %d\n", compute_zigzag_sum(matrix, n));

    for (int i = 0; i < n; i++) free(*(matrix + i));
    free(matrix);
    return 0;
}
