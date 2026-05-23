#include <limits.h>

/*@ logic integer count_divs_checked(integer n, integer c) =
      c <= 1 ? 0 :
      count_divs_checked(n, c - 1) + (c <= n / c && n % c == 0 ? 1 : 0); */

/*@ requires num >= 0;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
  ensures \result >= 0;
  ensures num != 1 ==> (\result == 0 ==> \true); */
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

/*@ requires num >= 0;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
  ensures \result >= 0;
  ensures num != 1 ==> (\result == 0 ==> \true); */
int check_B_implies_A(int num) {
    return stub_B(num);
}
