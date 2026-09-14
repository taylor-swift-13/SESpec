#include <stddef.h>

int * search(int * arr, int len, int val);

int * search(int * arr, int len, int val) {
    int i = 0;
    while (i < len) {
        if (arr[i] == val) return arr + i;
        i = i + 1;
    }
    return (int *)0;
}
