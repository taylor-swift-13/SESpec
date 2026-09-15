#include <limits.h>

/*@ logic integer max_prefix(int* positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (positions[lo] > max_prefix(positions, lo + 1, hi) ? positions[lo] : max_prefix(positions, lo + 1, hi)); */

/*@ requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < positions_len ==> positions[k] <= \result; */
int stub_A(int * positions, int positions_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * positions, int positions_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * positions, int positions_len) {
    return stub_A(positions, positions_len);
}

/*@ requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < positions_len ==> positions[k] <= \result; */
int check_B_implies_A(int * positions, int positions_len) {
    return stub_B(positions, positions_len);
}
