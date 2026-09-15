
#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);

/*@
  requires 0 <= m < 10000;
  requires 0 <= n < 10000;
  requires -148 <= n <= 148;
  assigns \nothing;
*/
int foo9(int m, int n);

#include <assert.h>

/*@
  requires c < 150;
  requires -(150 - c) <= n <= (150 - c);
  decreases 150 - c;
  assigns \nothing;
*/
int foo36_helper1_c9(int m, int n, int c);
int foo9(int m, int n);

/*@
  requires c < 149;
  requires -(148 - c) <= n <= (148 - c);
  decreases 148 - c;
  assigns \nothing;
*/
int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}


/*@
  requires 0 <= m < 10000;
  requires 0 <= n < 10000;
  requires -148 <= n <= 148;
  assigns \nothing;
  ensures (\old(m) < 0 || \old(m) >= 10000 || \old(n) < 0 || \old(n) >= 10000) ==> \result == -1;
  ensures \result == 0 || \result == 1;
  ensures \result >= -1 && \result <= 1;
*/
int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}
