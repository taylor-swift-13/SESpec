#include <limits.h>

/*@ predicate divides(integer a, integer b) = a != 0 && b % a == 0; */

/*@ assigns \nothing;
ensures \result >= 0; */
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
ensures \result >= 0; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
