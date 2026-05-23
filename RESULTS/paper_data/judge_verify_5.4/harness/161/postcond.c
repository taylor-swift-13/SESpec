#include <limits.h>

/*@ requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  requires array >= 0;
  requires array <= positions_len;
  assigns positions[0..array-1];
  ensures (\forall integer k; 0 <= k < array ==> \at(positions[k],Pre) == k + 1) ==> 1 <= \result <= array + 1;
  ensures (\exists integer k; 0 <= k < array && \at(positions[k],Pre) != k + 1) ==> 1 <= \result <= array + 1; */
int stub_A(int * positions, int positions_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * positions, int positions_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * positions, int positions_len, int array) {
    return stub_A(positions, positions_len, array);
}

/*@ requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  requires array >= 0;
  requires array <= positions_len;
  assigns positions[0..array-1];
  ensures (\forall integer k; 0 <= k < array ==> \at(positions[k],Pre) == k + 1) ==> 1 <= \result <= array + 1;
  ensures (\exists integer k; 0 <= k < array && \at(positions[k],Pre) != k + 1) ==> 1 <= \result <= array + 1; */
int check_B_implies_A(int * positions, int positions_len, int array) {
    return stub_B(positions, positions_len, array);
}
