#include <assert.h>

/*@
    requires n >= 0 || n < 0;
    requires c >= 0;
    requires c < 150;
    ensures \result == m + n;
    assigns \nothing;
*/
int addition(int m, int n, int c);

/*@
    requires m >= 0 && m < 10000;
    requires n >= 0 && n < 10000;
    ensures \result == 1 || \result == -1;
    ensures \result == 1 ==> m + n >= 0 && m + n < 20000;
    ensures \result == -1 ==> m + n < 0 || m + n >= 20000;
    assigns \nothing;
*/
int f(int m, int n);

int addition(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return addition(m + 1, n - 1, c + 1);
    return addition(m - 1, n + 1, c + 1);
}

int f(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = addition(m, n, 0);
    return result == m + n;
}
