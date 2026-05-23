#include <limits.h>


/*@
  logic integer count_pairs(int* pairs, integer lo, integer hi, integer p) =
    lo >= hi ? 0 :
    count_pairs(pairs, lo, hi - 1, p) +
    (pairs[lo] + pairs[hi - 1] == p ? 1 : 0);
*/

/*@requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  requires 0 <= num <= pairs_len;
  assigns \nothing;
  ensures \result >= 0;*/
int stub_A(int * pairs, int pairs_len, int num, int p);

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/
int stub_B(int * pairs, int pairs_len, int num, int p);

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/
int check_A_implies_B(int * pairs, int pairs_len, int num, int p) {
    return stub_A(pairs, pairs_len, num, p);
}

/*@requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  requires 0 <= num <= pairs_len;
  assigns \nothing;
  ensures \result >= 0;*/
int check_B_implies_A(int * pairs, int pairs_len, int num, int p) {
    return stub_B(pairs, pairs_len, num, p);
}
