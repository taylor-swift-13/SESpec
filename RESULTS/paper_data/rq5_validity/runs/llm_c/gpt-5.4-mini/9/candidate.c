#include <assert.h>

/*@
  requires c <= 150;
  assigns \nothing;
  ensures n == 0 ==> \result == m;
  ensures n != 0 ==> \result == addition(m,n,c); 
*/
int addition(int m, int n, int c);
int f(int m, int n);

/*@ 
  requires c <= 150;
  assigns \nothing;
  behavior base:
    assumes n == 0;
    ensures \result == m;
  behavior step_pos:
    assumes n > 0 && c < 150;
    ensures \result == addition(m + 1, n - 1, c + 1);
  behavior step_neg:
    assumes n < 0 && c < 150;
    ensures \result == addition(m - 1, n + 1, c + 1);
  complete behaviors base, step_pos, step_neg;
  disjoint behaviors base, step_pos, step_neg;
*/
int addition(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return addition(m + 1, n - 1, c + 1);
    return addition(m - 1, n + 1, c + 1);
}

/*@ 
  requires \true;
  assigns \nothing;
  ensures (m < 0 || m >= 10000 || n < 0 || n >= 10000) ==> \result == -1;
  ensures (0 <= m < 10000 && 0 <= n < 10000) ==> \result == (addition(m,n,0) == m + n);
*/
int f(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = addition(m, n, 0);
    return result == m + n;
}
