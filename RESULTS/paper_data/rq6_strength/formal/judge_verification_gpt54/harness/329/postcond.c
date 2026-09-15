#include <limits.h>

/*@ logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n; */
/*@ logic integer sum_upto(integer n) =
    n <= 0 ? 0 : sum_upto(n - 1) + n; */

/*@ requires diff >= 0;
  assigns \nothing; */
int stub_A(int diff);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int diff);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int diff) {
    return stub_A(diff);
}

/*@ requires diff >= 0;
  assigns \nothing; */
int check_B_implies_A(int diff) {
    return stub_B(diff);
}
