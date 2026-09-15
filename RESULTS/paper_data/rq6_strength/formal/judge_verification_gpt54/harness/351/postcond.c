#include <limits.h>

/*@ assigns \nothing;
  ensures !(\old(number) > 0) ==> (\result == \old(number)); */
int stub_A(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@ assigns \nothing;
  ensures !(\old(number) > 0) ==> (\result == \old(number)); */
int check_B_implies_A(int number) {
    return stub_B(number);
}
