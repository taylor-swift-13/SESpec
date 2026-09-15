#include <limits.h>

/*@ logic integer count_div(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_div(n, lo, hi - 1) + ((n % (hi - 1)) == 0 ? 1 : 0); */

/*@ requires number >= 0;
  assigns \nothing;
  ensures \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 == 0) ==> \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 != 0) ==> \result != \null; */
const char * stub_A(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * stub_B(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * check_A_implies_B(int number) {
    return stub_A(number);
}

/*@ requires number >= 0;
  assigns \nothing;
  ensures \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 == 0) ==> \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 != 0) ==> \result != \null; */
const char * check_B_implies_A(int number) {
    return stub_B(number);
}
