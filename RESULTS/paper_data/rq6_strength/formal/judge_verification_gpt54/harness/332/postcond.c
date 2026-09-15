#include <limits.h>

/*@ logic integer prod10(integer a, integer b) =
      b < a ? 1 : (prod10(a, b - 1) * (b % 10)) % 10; */

/*@ assigns \nothing;
  ensures (num == c) ==> \result == 1;
  ensures ((c - num) >= 5) ==> \result == 0; */
int stub_A(int num, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int num, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int num, int c) {
    return stub_A(num, c);
}

/*@ assigns \nothing;
  ensures (num == c) ==> \result == 1;
  ensures ((c - num) >= 5) ==> \result == 0; */
int check_B_implies_A(int num, int c) {
    return stub_B(num, c);
}
