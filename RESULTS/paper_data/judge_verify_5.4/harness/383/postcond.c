#include <limits.h>

/*@ logic integer divcount(integer n, integer i) =
      i <= 1 ? 0 : divcount(n, i - 1) + ((n % (i - 1)) == 0 ? 1 : 0); */

/*@ requires n >= 0;
  assigns \nothing;
  ensures \result == divcount(n, n + 1);
  ensures \result >= 0;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result >= 1; */
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

/*@ requires n >= 0;
  assigns \nothing;
  ensures \result == divcount(n, n + 1);
  ensures \result >= 0;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result >= 1; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
