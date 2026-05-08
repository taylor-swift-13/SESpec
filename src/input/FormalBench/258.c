#include <stdlib.h>

int foo258(int n);

int foo258(int n) {

        int *f = (int *)malloc(sizeof(int) * (n + 1));
int f_len = n + 1;
        f[0] = 0;
        for (int i = 0; i <= n - 1; i++) {
            f[i + 1] = f[i] + 6 * i + 1;
        }
        return f[n];
}
