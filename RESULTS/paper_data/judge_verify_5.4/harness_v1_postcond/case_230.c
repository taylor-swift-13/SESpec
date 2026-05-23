#include <limits.h>


/*@ logic integer mismatch_suffix(int* pairs, integer i, integer lo, integer hi) =
      lo >= hi ? 0 :
      mismatch_suffix(pairs, i, lo, hi - 1) + ((pairs[i] != pairs[hi - 1]) ? 1 : 0);
*/

/*@ logic integer prefix_mismatch(int* pairs, integer n, integer idx) =
      idx <= 0 ? 0 :
      prefix_mismatch(pairs, n, idx - 1) + mismatch_suffix(pairs, idx - 1, idx, n);

/*@requires pairs_len >= 0;
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  assigns \nothing;
  ensures \result == prefix_mismatch(pairs, pairs_len, pairs_len);
  ensures \result >= 0;
  ensures pairs_len <= 1 ==> \result == 0;
  ensures pairs_len > 1 ==> \result == prefix_mismatch(pairs, pairs_len, pairs_len);*/
int stub_A(int * pairs, int pairs_len, int array);

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/
int stub_B(int * pairs, int pairs_len, int array);

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/
int check_A_implies_B(int * pairs, int pairs_len, int array) {
    return stub_A(pairs, pairs_len, array);
}

/*@requires pairs_len >= 0;
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  assigns \nothing;
  ensures \result == prefix_mismatch(pairs, pairs_len, pairs_len);
  ensures \result >= 0;
  ensures pairs_len <= 1 ==> \result == 0;
  ensures pairs_len > 1 ==> \result == prefix_mismatch(pairs, pairs_len, pairs_len);*/
int check_B_implies_A(int * pairs, int pairs_len, int array) {
    return stub_B(pairs, pairs_len, array);
}
