#include <limits.h>

/*@ logic integer divcount(integer n, integer d) =
    d <= 0 ? 0 : divcount(n, d - 1) + ((d != 0 && n % d == 0) ? 1 : 0); */

/*@ assigns \nothing;
  
  ensures \result >= 0;
  ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
  ensures \old(z) >= 0 ==> \result == divcount(num, \old(z));
  ensures \old(z) < 0 ==> \result == divcount(num, -\old(z)); */
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
  ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
  ensures \old(z) >= 0 ==> \result == divcount(num, \old(z));
  ensures \old(z) < 0 ==> \result == divcount(num, -\old(z)); */
int check_B_implies_A(int num, int z) {
    return stub_B(num, z);
}
