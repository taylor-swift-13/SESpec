#include <limits.h>

/*@ logic integer odd_divisor_sum(integer n, integer i) =
      i < 1 ? 0 :
      odd_divisor_sum(n, i - 1) + (((n % i == 0) && (i % 2 != 0)) ? i : 0); */

/*@ assigns \nothing;
  ensures \result >= 0;
  ensures \at(n,Pre) < 1 ==> \result >= 0;
  ensures \at(n,Pre) > 0 ==> \result >= 0;
  ensures \result >= 0; */
int stub_A(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ assigns \nothing;
  ensures \result >= 0;
  ensures \at(n,Pre) < 1 ==> \result >= 0;
  ensures \at(n,Pre) > 0 ==> \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
