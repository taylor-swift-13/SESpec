#include <limits.h>

/*@ logic integer count_divs(integer num, integer size) =
      size < 2 ? 0 :
      count_divs(num, size - 1) + (num % size == 0 ? 1 : 0); */

/*@ requires num >= 1;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures \result >= 0; */
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

/*@ requires num >= 1;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures \result >= 0; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
