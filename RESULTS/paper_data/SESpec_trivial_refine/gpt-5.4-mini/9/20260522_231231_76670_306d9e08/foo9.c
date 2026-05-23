
#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);

/*@ 
  requires 0 <= m < 10000;
  requires 0 <= n < 150;
  assigns \nothing;
  ensures \result == 1;
*/
int foo9(int m, int n);

/*@ 
  requires 0 <= n;
  requires c + n < 150;
  requires m + n <= 2147483647;
  requires m - n >= (-2147483647 - 1);
  decreases n;
  assigns \nothing;
  ensures \result == m + n;
*/
int foo36_helper1_c9(int m, int n, int c);

/*@ 
  requires 0 <= n;
  requires c + n < 150;
  requires m + n <= 2147483647;
  requires m - n >= (-2147483647 - 1);
  decreases n;
  assigns \nothing;
  ensures \result == m + n;
*/
int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}

int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}
