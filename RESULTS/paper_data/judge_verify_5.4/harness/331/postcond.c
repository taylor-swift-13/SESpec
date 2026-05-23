#include <limits.h>

/*@ logic integer prod_mod(integer i, integer j) =
    i > j ? 1 : ((i % 10) * prod_mod(i + 1, j)) % 10; */

/*@ requires n >= 0;
  requires c >= 0;
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  ensures \result >= 0 && \result <= 9; */
int stub_A(int n, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int c) {
    return stub_A(n, c);
}

/*@ requires n >= 0;
  requires c >= 0;
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  ensures \result >= 0 && \result <= 9; */
int check_B_implies_A(int n, int c) {
    return stub_B(n, c);
}
