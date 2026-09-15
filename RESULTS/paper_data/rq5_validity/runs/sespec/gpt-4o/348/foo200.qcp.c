#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo200(int a, int n, int l, int r);

int foo200(int a, int n, int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (l <= i && i <= r + 1) &&
(r == r@pre) &&
(l == l@pre) &&
(n == n@pre) &&
(a == a@pre
      loop assigns i, count)
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