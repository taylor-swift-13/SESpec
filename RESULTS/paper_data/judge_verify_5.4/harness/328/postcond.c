#include <limits.h>

/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n; */

/*@ requires 0 <= diff <= 1;
  assigns \nothing;
  ensures \result == \result; */
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

/*@ requires 0 <= diff <= 1;
  assigns \nothing;
  ensures \result == \result; */
int check_B_implies_A(int diff) {
    return stub_B(diff);
}
