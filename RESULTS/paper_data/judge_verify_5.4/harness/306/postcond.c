#include <limits.h>
#include <stdlib.h>

/*@ logic integer lucas_seq(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      lucas_seq(n - 1) + lucas_seq(n - 2); */

/*@ requires n >= 1;
  ensures n >= 1 ==> \result == lucas_seq(n - 1) + lucas_seq(n - 2) || n == 1;
  ensures n >= 1 ==> \true;
  ensures n >= 1 ==> \true; */
int stub_A(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ requires n >= 1;
  ensures n >= 1 ==> \result == lucas_seq(n - 1) + lucas_seq(n - 2) || n == 1;
  ensures n >= 1 ==> \true;
  ensures n >= 1 ==> \true; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
