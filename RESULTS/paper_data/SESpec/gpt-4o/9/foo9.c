
#include <assert.h>

/*@ 
  logic integer foo36_logic(integer m, integer n, integer c) =
    (n == 0) ? m :
    (c >= 150) ? -1 :
    (n > 0) ? foo36_logic(m + 1, n - 1, c + 1) :
              foo36_logic(m - 1, n + 1, c + 1);
*/

/*@
  requires c < 150;
  decreases n >= 0 ? n : -n;
  assigns \nothing;
  ensures (n == 0) ==> (\result == m);
  ensures (n != 0 && c < 150) ==> (\result == foo36_logic(m, n, c));
*/
int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}

/*@
  requires m >= 0 && m < 10000;
  requires n >= 0 && n < 10000;
  assigns \nothing;
  ensures (m < 0 || m >= 10000 || n < 0 || n >= 10000) ==> (\result == -1);
  ensures (m >= 0 && m < 10000 && n >= 0 && n < 10000) ==> (
      foo36_logic(m, n, 0) == m + n ? \result == 1 : \result == 0
  );
*/
int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}
