#include <limits.h>

/*@ assigns \nothing;
  ensures \result >= 0;
  ensures \result == 0 || \result > 0; */
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

/*@ assigns \nothing;
  ensures \result >= 0;
  ensures \result == 0 || \result > 0; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
