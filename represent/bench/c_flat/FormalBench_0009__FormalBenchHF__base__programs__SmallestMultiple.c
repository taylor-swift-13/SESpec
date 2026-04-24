#include <stdlib.h>

int smallestMultiple(int n);

int smallestMultiple(int n) {

        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int *factors = (int *)malloc(sizeof(int) * (n));
int factors_len = n;
        for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
        while (1) {
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
        }
}
