#include <limits.h>

int foo55(int * a, int a_len);

int foo55(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
}
