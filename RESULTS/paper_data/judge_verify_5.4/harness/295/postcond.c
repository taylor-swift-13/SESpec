#include <limits.h>
#include <stdlib.h>

/*@ logic integer fib295(integer n) =
      n <= 0 ? 2 :
      n == 1 ? 1 :
      fib295(n - 1) + fib295(n - 2); */

/*@ requires num >= 1;
    ensures \result == fib295(num); */
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
    ensures \result == fib295(num); */
int check_B_implies_A(int num) {
    return stub_B(num);
}
