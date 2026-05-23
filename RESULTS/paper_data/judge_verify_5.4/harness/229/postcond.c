#include <limits.h>
#include <stdlib.h>

/*@ logic integer pow2(integer n) =
      n <= 0 ? 1 : 2 * pow2(n - 1); */

/*@ requires seed >= 0;
  
  ensures \result >= 1; */
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

/*@ requires seed >= 0;
  
  ensures \result >= 1; */
int check_B_implies_A(int seed) {
    return stub_B(seed);
}
