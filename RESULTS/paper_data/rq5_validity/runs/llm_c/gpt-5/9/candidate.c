#include <assert.h>

/*@ 
  requires c >= 0;
  requires c < 150;
  assigns \nothing;
  terminates \true;
  ensures \result == m + n;
*/
int addition(int m, int n, int c);

/*@
  assigns \nothing;
  terminates \true;
  ensures (m < 0 || m >= 10000 || n < 0 || n >= 10000) ==> \result == -1;
  ensures (0 <= m < 10000 && 0 <= n < 10000) ==> (\result == 0 || \result == 1);
  ensures (0 <= m < 10000 && 0 <= n < 10000) ==> (\result == 1 <==> (m + n < 150));
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
