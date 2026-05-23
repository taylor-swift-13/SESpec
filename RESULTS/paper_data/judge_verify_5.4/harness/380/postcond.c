#include <limits.h>

/*@ logic integer proper_divisor_sum(integer n, integer i) =
      i <= 1 ? 0 :
      proper_divisor_sum(n, i - 1) +
      (((i - 1) != 0 && n % (i - 1) == 0) ? (i - 1) : 0); */

/*@ assigns \nothing;
  
  ensures \result >= 0; */
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

/*@ assigns \nothing;
  
  ensures \result >= 0; */
int check_B_implies_A(int number) {
    return stub_B(number);
}
