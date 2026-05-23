#include <limits.h>

/*@ requires n >= 0;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= n;
  ensures \result == 0 <==> (\forall integer k; 1 <= k <= n ==> (k % x) != y);
  ensures \result > 0 ==> ((\result % x) == y);
  ensures \result > 0 ==> (\forall integer k; \result < k <= n ==> (k % x) != y);
  ensures \result > 0 ==> (\forall integer k; 1 <= k <= n && (k % x) == y ==> k <= \result); */
int stub_A(int n, int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int x, int y) {
    return stub_A(n, x, y);
}

/*@ requires n >= 0;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= n;
  ensures \result == 0 <==> (\forall integer k; 1 <= k <= n ==> (k % x) != y);
  ensures \result > 0 ==> ((\result % x) == y);
  ensures \result > 0 ==> (\forall integer k; \result < k <= n ==> (k % x) != y);
  ensures \result > 0 ==> (\forall integer k; 1 <= k <= n && (k % x) == y ==> k <= \result); */
int check_B_implies_A(int n, int x, int y) {
    return stub_B(n, x, y);
}
