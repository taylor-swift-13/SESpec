#include <limits.h>

/*@ requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  assigns \nothing;
  ensures \result >= 0; */
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

/*@ requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  assigns \nothing;
  ensures \result >= 0; */
int check_B_implies_A(int * pairs, int pairs_len, int array) {
    return stub_B(pairs, pairs_len, array);
}
