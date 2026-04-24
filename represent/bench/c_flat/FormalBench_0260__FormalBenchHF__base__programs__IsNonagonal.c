#include <stdlib.h>

int isNonagonal(int n);

int isNonagonal(int n) {

        int *f = (int *)malloc(sizeof(int) * (n + 1));
int f_len = n + 1;
        f[0] = 0;
        for (int i = 0; i <= n - 1; i++) {
            f[i + 1] = f[i] + 7 * i + 1;
        }
        return f[n];
}
