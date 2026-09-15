#include <limits.h>

/*@ assigns \nothing;
  ensures \result == 0 <==> (\exists integer k; 2 <= k <= a / 2 && a % k == 0);
  ensures \result == 1 <==> (\forall integer k; 2 <= k <= a / 2 ==> a % k != 0);
  ensures \result == 0 || \result == 1;
  ensures a == \old(a); */
int stub_A(int a);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int a);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int a) {
    return stub_A(a);
}

/*@ assigns \nothing;
  ensures \result == 0 <==> (\exists integer k; 2 <= k <= a / 2 && a % k == 0);
  ensures \result == 1 <==> (\forall integer k; 2 <= k <= a / 2 ==> a % k != 0);
  ensures \result == 0 || \result == 1;
  ensures a == \old(a); */
int check_B_implies_A(int a) {
    return stub_B(a);
}
