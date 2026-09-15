#include <limits.h>

/*@ assigns \nothing;
  ensures n == 1 ==> \result == 1;
  ensures n != 1 && n < 4 ==> \result >= 0;
  ensures n > 1 && (\forall integer d; 2 <= d <= n / 2 ==> n % d != 0) ==> \result >= 0;
  ensures n > 1 && (\exists integer d; 2 <= d <= n / 2 && n % d == 0) ==> \result >= 0;
  ensures \result >= 0; */
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
  ensures n == 1 ==> \result == 1;
  ensures n != 1 && n < 4 ==> \result >= 0;
  ensures n > 1 && (\forall integer d; 2 <= d <= n / 2 ==> n % d != 0) ==> \result >= 0;
  ensures n > 1 && (\exists integer d; 2 <= d <= n / 2 && n % d == 0) ==> \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
