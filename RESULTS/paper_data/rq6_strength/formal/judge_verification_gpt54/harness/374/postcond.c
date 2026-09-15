#include <limits.h>

/*@ logic integer count_div(integer n, integer k) =
    k <= 0 ? 0 : count_div(n, k - 1) + ((n % k) == 0 ? 1 : 0); */

/*@ requires number >= 0;
   assigns \nothing;
   ensures \result == count_div(number, number);
   ensures number == 0 ==> \result == 0;
   ensures number > 0 ==> \result >= 0; */
int stub_A(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@ requires number >= 0;
   assigns \nothing;
   ensures \result == count_div(number, number);
   ensures number == 0 ==> \result == 0;
   ensures number > 0 ==> \result >= 0; */
int check_B_implies_A(int number) {
    return stub_B(number);
}
