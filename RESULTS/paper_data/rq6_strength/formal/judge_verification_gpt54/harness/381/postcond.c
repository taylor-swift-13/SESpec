#include <limits.h>

/*@ logic integer common_divisor_count(integer x, integer y, integer n) =
    n <= 0 ? 0 :
    common_divisor_count(x, y, n - 1) +
    ((x % n == 0 && y % n == 0) ? 1 : 0); */

/*@ assigns \nothing;
  
  ensures \result >= 0; */
int stub_A(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int x, int y) {
    return stub_A(x, y);
}

/*@ assigns \nothing;
  
  ensures \result >= 0; */
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
