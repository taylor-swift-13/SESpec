#include <stdlib.h>

int foo8(int * arr, int arr_len, int n);

int foo8(int * arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * (n));
int mpis_len = n;
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }
        int max = mpis[0];
        for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
        return max;
}
