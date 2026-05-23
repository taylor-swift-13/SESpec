#include <limits.h>

/*@ logic integer prod(integer n, integer i) =
    i <= 0 ? 1 : prod(n, i - 1) * (n - i + 1) / i; */

/*@ requires 0 <= n;
  requires 0 <= k <= n;
  assigns \nothing;
  ensures k == \old(k) || k == n - \old(k);
  ensures \old(k) > n - \old(k) ==> k == k;
  ensures \old(k) <= n - \old(k) ==> k == \old(k);
  ensures \result == \result;
  ensures \result >= 0; */
int stub_A(int n, int k);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int k);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int k) {
    return stub_A(n, k);
}

/*@ requires 0 <= n;
  requires 0 <= k <= n;
  assigns \nothing;
  ensures k == \old(k) || k == n - \old(k);
  ensures \old(k) > n - \old(k) ==> k == k;
  ensures \old(k) <= n - \old(k) ==> k == \old(k);
  ensures \result == \result;
  ensures \result >= 0; */
int check_B_implies_A(int n, int k) {
    return stub_B(n, k);
}
