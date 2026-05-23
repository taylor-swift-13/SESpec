#include <limits.h>

/*@ logic integer count_divisors(integer n, integer start, integer end) =
      end <= start ? 0 :
      ((n % (end - 1) == 0)
         ? count_divisors(n, start, end - 1) + 1
         : count_divisors(n, start, end - 1)); */

/*@ assigns \nothing;
  ensures \result != \null; */
const char * stub_A(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * stub_B(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ assigns \nothing;
  ensures \result != \null; */
const char * check_B_implies_A(int n) {
    return stub_B(n);
}
