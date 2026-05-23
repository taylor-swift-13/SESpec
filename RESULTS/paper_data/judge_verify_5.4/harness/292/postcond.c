#include <limits.h>
#include <stdlib.h>

/*@ logic integer rec(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * rec(n - 1) + rec(n - 2)) % 1000000000; */

/*@ requires seed == 1;
  
  ensures seed >= 1 ==> \result >= 0;
  ensures seed == 1 ==> \result == 1;
  ensures seed >= 2 ==> \result == (2 * rec(seed - 1) + rec(seed - 2)) % 1000000000; */
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

/*@ requires seed == 1;
  
  ensures seed >= 1 ==> \result >= 0;
  ensures seed == 1 ==> \result == 1;
  ensures seed >= 2 ==> \result == (2 * rec(seed - 1) + rec(seed - 2)) % 1000000000; */
int check_B_implies_A(int seed) {
    return stub_B(seed);
}
