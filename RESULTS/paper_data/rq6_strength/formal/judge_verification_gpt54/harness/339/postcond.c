#include <limits.h>

/*@ logic integer divcount(integer n, integer i) =
      i <= 0 ? 0 : divcount(n, i - 1) + (n % i == 0 ? 1 : 0); */

/*@ assigns \nothing;
  
  ensures \result >= 0;
  ensures \old(z) == 0 ==> \result == 0; */
int stub_A(int num, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int num, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int num, int z) {
    return stub_A(num, z);
}

/*@ assigns \nothing;
  
  ensures \result >= 0;
  ensures \old(z) == 0 ==> \result == 0; */
int check_B_implies_A(int num, int z) {
    return stub_B(num, z);
}
