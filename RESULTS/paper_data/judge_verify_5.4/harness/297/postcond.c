#include <limits.h>
#include <stdlib.h>

/*@ logic integer fib(integer n) =
      n <= 1 ? n : fib(n - 1) + fib(n - 2); */

/*@ requires seed >= 1; */
int stub_A(int seed);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int seed);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int seed) {
    return stub_A(seed);
}

/*@ requires seed >= 1; */
int check_B_implies_A(int seed) {
    return stub_B(seed);
}
