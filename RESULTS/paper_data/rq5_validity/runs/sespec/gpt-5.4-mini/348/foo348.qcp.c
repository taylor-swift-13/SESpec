#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (nondiv_count : Z -> Z -> Z -> Z) */
int foo348(int a, int n, int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (i >= l) &&
    (count >= 0) &&
    (count <= i - l) &&
    (count == nondiv_count(a, l, i - 1)) &&
    (forall (j:Z), l <= j && j < i => (j % a == 0 || j % a != 0)) &&
    ((i == l) => (count == 0)) &&
    ((i > l) => (count == nondiv_count(a, l, i - 1)))
    */
for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
        return -1;
}