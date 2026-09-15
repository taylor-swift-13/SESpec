
#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);

/*@
  requires 0 <= m && m < 10000;
  requires 0 <= n && n < 10000;
  requires (n >= 0 ? n : -n) <= 150;
  assigns \nothing;
*/
int foo9(int m, int n);

#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);
int foo9(int m, int n);

/*@
  requires ( (n >= 0 ? n : -n) + c ) <= 150;
  decreases (n >= 0 ? n : -n);
  assigns \nothing;
  ensures \result == m + n;
  ensures \result >= m <==> n >= 0;
  ensures \result <= m <==> n <= 0;
  ensures \result == m <==> n == 0;
*/
int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}


/*@
  requires 0 <= m && m < 10000;
  requires 0 <= n && n < 10000;
  requires (n >= 0 ? n : -n) <= 150;
  assigns \nothing;
  ensures ((m < 0 || m >= 10000) || (n < 0 || n >= 10000)) ==> \result == -1;
  ensures (0 <= m && m < 10000 && 0 <= n && n < 10000 && ((n >= 0 ? n : -n) <= 150)) ==> \result == 1;
  ensures \result == -1 <==> ((m < 0 || m >= 10000) || (n < 0 || n >= 10000));
  ensures (0 <= m && m < 10000 && 0 <= n && n < 10000) ==> \result == 1;
  ensures (\result == -1) || (\result == 1);
  ensures \result == ( ((m < 0 || m >= 10000) || (n < 0 || n >= 10000)) ? -1 : 1 );
*/
int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}
