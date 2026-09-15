#include <limits.h>

/*@ logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1); */

/*@ requires n >= 1;
  requires n <= 4;
  assigns \nothing;
  ensures \result >= 0;
  ensures 0 <= \result && \result <= 9;
  ensures n == 1 ==> \result >= 0;
  ensures n == 2 ==> \result >= 0;
  ensures n == 3 ==> \result >= 0;
  ensures n == 4 ==> \result >= 0;
  ensures n >= 5 ==> \result >= 0; */
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

/*@ requires n >= 1;
  requires n <= 4;
  assigns \nothing;
  ensures \result >= 0;
  ensures 0 <= \result && \result <= 9;
  ensures n == 1 ==> \result >= 0;
  ensures n == 2 ==> \result >= 0;
  ensures n == 3 ==> \result >= 0;
  ensures n == 4 ==> \result >= 0;
  ensures n >= 5 ==> \result >= 0; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
