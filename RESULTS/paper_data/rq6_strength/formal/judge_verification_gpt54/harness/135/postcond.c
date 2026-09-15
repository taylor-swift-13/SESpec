#include <limits.h>

/*@ logic integer ipow(integer x, integer n) =
      n <= 0 ? 1 : x * ipow(x, n - 1); */

/*@ requires n >= 0;
  assigns \nothing;
  ensures \result == ipow(x, n);
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> \result == x * ipow(x, n - 1);
  ensures x == 1 ==> \result == ipow(x, n);
  ensures x == 0 && n > 0 ==> \result == 0; */
int stub_A(int x, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int x, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int x, int n) {
    return stub_A(x, n);
}

/*@ requires n >= 0;
  assigns \nothing;
  ensures \result == ipow(x, n);
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> \result == x * ipow(x, n - 1);
  ensures x == 1 ==> \result == ipow(x, n);
  ensures x == 0 && n > 0 ==> \result == 0; */
int check_B_implies_A(int x, int n) {
    return stub_B(x, n);
}
