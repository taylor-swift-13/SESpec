#include <limits.h>

/*@ logic integer pow4(integer k) = k <= 0 ? 1 : 4 * pow4(k - 1); */

/*@ assigns \nothing;
  ensures n <= 0 ==> \result == 0;
  ensures n > 0 && n % 4 != 0 ==> (\result == 1 ==> n > 0);
  ensures n > 0 && n % 4 == 0 ==> (\result == 1 ==> n > 0);
  ensures n > 0 ==> (\result == 1 || \result == 0);
  ensures \result == 1 ==> n > 0; */
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
  ensures n <= 0 ==> \result == 0;
  ensures n > 0 && n % 4 != 0 ==> (\result == 1 ==> n > 0);
  ensures n > 0 && n % 4 == 0 ==> (\result == 1 ==> n > 0);
  ensures n > 0 ==> (\result == 1 || \result == 0);
  ensures \result == 1 ==> n > 0; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
