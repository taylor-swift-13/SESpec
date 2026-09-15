#include <assert.h>

/*@
    requires 0 <= c && c <= 150 && c - 150 <= n && n <= 150 - c;
    assigns \nothing;
    ensures \result == m + n;
    decreases 150 - c;
*/
int addition(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return addition(m + 1, n - 1, c + 1);
    return addition(m - 1, n + 1, c + 1);
}

/*@
    requires 0 <= m && m < 10000 && 0 <= n && n < 10000 && n <= 150;
    assigns \nothing;
    ensures \result == 1;
*/
int f(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = addition(m, n, 0);
    return result == m + n;
}
