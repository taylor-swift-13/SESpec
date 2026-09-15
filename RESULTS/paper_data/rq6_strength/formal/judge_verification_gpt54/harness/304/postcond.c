#include <limits.h>
#include <stdlib.h>

/*@ logic integer pell_rec(integer k) =
      k <= 0 ? 0 :
      k == 1 ? 1 :
      (2 * pell_rec(k - 1) + pell_rec(k - 2)) % 1000000000; */

/*@ requires n >= 1;
  
  ensures \result == pell_rec(n); */
int stub_A(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ requires n >= 1;
  
  ensures \result == pell_rec(n); */
int check_B_implies_A(int n) {
    return stub_B(n);
}
