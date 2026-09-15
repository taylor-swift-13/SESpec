#include <limits.h>

/*@ logic integer max0(int* a, integer lo, integer hi) =
    lo >= hi ? 0 :
    (max0(a, lo, hi - 1) >= a[hi - 1] ? max0(a, lo, hi - 1) : a[hi - 1]); */

/*@ requires positions_len >= 0;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
  assigns \nothing;
  ensures \result == max0(positions, 0, positions_len);
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0; */
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

/*@ requires positions_len >= 0;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
  assigns \nothing;
  ensures \result == max0(positions, 0, positions_len);
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0; */
int check_B_implies_A(int * positions, int positions_len) {
    return stub_B(positions, positions_len);
}
