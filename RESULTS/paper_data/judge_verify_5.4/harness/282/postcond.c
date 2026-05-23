#include <limits.h>

/*@ logic integer divcount(integer n, integer low, integer high) =
    low >= high ? 0 : ((low != 0 && n % low == 0) ? 1 : 0) + divcount(n, low + 1, high); */

/*@ requires num >= 0;
  assigns \nothing;
  
  ensures \true;
  ensures \true; */
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

/*@ requires num >= 0;
  assigns \nothing;
  
  ensures \true;
  ensures \true; */
const char * check_B_implies_A(int num) {
    return stub_B(num);
}
