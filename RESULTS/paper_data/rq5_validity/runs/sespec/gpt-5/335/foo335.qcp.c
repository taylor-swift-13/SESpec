#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (mod10 : Z -> Z) */
/*@ Extern Coq (prod10 : Z -> Z -> Z) */
int foo335(int a, int b) 
/*@

Require emp
Ensure Results(__return)
*/{

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
           
  /*@ Inv
    (b == b@pre) &&
    (a == a@pre) &&
    ((b > a) => (a + 1 <= i && i <= b + 1)) &&
    ((b <= a) => (i == a + 1)) &&
    ((b > a) => (0 <= i - (a + 1) <= b - a)) &&
    (b - a < 5) &&
    (variable == prod10(a@pre + 1, i)) &&
    (-9 <= variable && variable <= 9) &&
    (forall (k:Z), a@pre + 1 <= k && k < i => -9 <= (k % 10) <= 9) &&
    (forall (k:Z), a@pre + 1 <= k && k < i => mod10(k) == (k % 10))
    */
for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
}