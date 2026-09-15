#include <limits.h>

/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */

/*@ ensures !(\at(num,Pre) > 0) ==> (\result == \at(num,Pre));
  assigns \nothing; */
int stub_A(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@ ensures !(\at(num,Pre) > 0) ==> (\result == \at(num,Pre));
  assigns \nothing; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
