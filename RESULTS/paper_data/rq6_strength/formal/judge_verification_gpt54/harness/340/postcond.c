#include <limits.h>

/*@ logic integer count_divisors(integer n, integer z) =
      z <= 0 ? 0 :
      count_divisors(n, z - 1) + ((n % z) == 0 ? 1 : 0); */

/*@ requires z >= 0;
  assigns \nothing;
  ensures z >= 0;
  ensures n == \old(n);
  
  ensures \result == count_divisors(n, (\old(z) >= 0 ? \old(z) : -\old(z)));
  ensures \result >= 0;
  ensures \result <= (\old(z) >= 0 ? \old(z) : -\old(z)); */
int stub_A(int n, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int z) {
    return stub_A(n, z);
}

/*@ requires z >= 0;
  assigns \nothing;
  ensures z >= 0;
  ensures n == \old(n);
  
  ensures \result == count_divisors(n, (\old(z) >= 0 ? \old(z) : -\old(z)));
  ensures \result >= 0;
  ensures \result <= (\old(z) >= 0 ? \old(z) : -\old(z)); */
int check_B_implies_A(int n, int z) {
    return stub_B(n, z);
}
