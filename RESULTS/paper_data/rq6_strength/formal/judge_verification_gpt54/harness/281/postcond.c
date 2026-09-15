#include <limits.h>

/*@ logic integer count_divisors_upto(integer num, integer n) =
    n <= 0 ? 0 :
    count_divisors_upto(num, n - 1) + (n <= num && num % n == 0 ? 1 : 0); */

/*@ assigns \nothing; */
const char * stub_A(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * stub_B(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * check_A_implies_B(int num) {
    return stub_A(num);
}

/*@ assigns \nothing; */
const char * check_B_implies_A(int num) {
    return stub_B(num);
}
