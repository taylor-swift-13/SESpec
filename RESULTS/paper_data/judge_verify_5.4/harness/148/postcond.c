#include <limits.h>

/*@ assigns \nothing;
  ensures \at(n, Pre) <= 0 ==> \result == 0;
  ensures \at(n, Pre) > 0 ==> (0 <= \result <= 1);
  ensures 0 <= \result <= 1; */
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

/*@ assigns \nothing;
  ensures \at(n, Pre) <= 0 ==> \result == 0;
  ensures \at(n, Pre) > 0 ==> (0 <= \result <= 1);
  ensures 0 <= \result <= 1; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
