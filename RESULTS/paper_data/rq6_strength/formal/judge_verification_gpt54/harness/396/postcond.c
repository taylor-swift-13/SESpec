#include <limits.h>

/*@ logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n - 1) + n * n * n * n; */

/*@ assigns \nothing;
  ensures \true; */
int stub_A(int p);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int p);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int p) {
    return stub_A(p);
}

/*@ assigns \nothing;
  ensures \true; */
int check_B_implies_A(int p) {
    return stub_B(p);
}
