#include <limits.h>

/*@ logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n; */
/*@ logic integer tri_sum(integer n) =
    n <= 0 ? 0 : tri_sum(n - 1) + n; */

/*@ requires diff >= 0;
  assigns \nothing;
  ensures \result == cube_sum(diff) - tri_sum(diff);
  ensures cube_sum(diff) >= 0;
  ensures tri_sum(diff) >= 0;
  ensures diff == 0 ==> \result == 0; */
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
  assigns \nothing;
  ensures \result == cube_sum(diff) - tri_sum(diff);
  ensures cube_sum(diff) >= 0;
  ensures tri_sum(diff) >= 0;
  ensures diff == 0 ==> \result == 0; */
int check_B_implies_A(int diff) {
    return stub_B(diff);
}
