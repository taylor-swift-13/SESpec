#include <limits.h>

/*@ assigns \nothing;
  ensures (0 <= \old(x)) ==> (\result == -1 || (\result * \result) <= \old(x));
  ensures (!(0 <= \old(x))) ==> (\result == -1);
  ensures (0 <= \old(x)) ==> (\result >= -1); */
int stub_A(int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int x) {
    return stub_A(x);
}

/*@ assigns \nothing;
  ensures (0 <= \old(x)) ==> (\result == -1 || (\result * \result) <= \old(x));
  ensures (!(0 <= \old(x))) ==> (\result == -1);
  ensures (0 <= \old(x)) ==> (\result >= -1); */
int check_B_implies_A(int x) {
    return stub_B(x);
}
