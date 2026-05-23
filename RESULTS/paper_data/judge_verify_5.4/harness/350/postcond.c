#include <limits.h>

/*@ logic integer selected_even_bits(integer x) =
      x <= 0 ? 0 : ((x % 2 == 1) ? 1 : 0) + 4 * selected_even_bits(x / 4); */

/*@ assigns \nothing;
   ensures num <= 0 ==> \result == num; */
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
   ensures num <= 0 ==> \result == num; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
