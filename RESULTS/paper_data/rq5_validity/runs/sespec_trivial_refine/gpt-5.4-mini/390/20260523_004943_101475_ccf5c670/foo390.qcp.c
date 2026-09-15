#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (fallfact : Z -> Z -> Z) */

int foo390(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 1;
        int i = 1;
       
  /*0*/ 
 /*@ Inv
    (i >= 1) &&
    (res == \product(integer j 1 <= j && j < i n - j + 1))
    */
while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}