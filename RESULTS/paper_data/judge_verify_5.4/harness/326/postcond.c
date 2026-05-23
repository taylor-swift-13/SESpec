#include <limits.h>

/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires num <= 1;
  assigns \nothing;
  ensures 0 <= \result <= 9; */
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

/*@ requires num <= 1;
  assigns \nothing;
  ensures 0 <= \result <= 9; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
