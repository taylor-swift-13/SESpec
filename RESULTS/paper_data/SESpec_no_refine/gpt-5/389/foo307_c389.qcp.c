#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo307_c389(int p, int q, int n);

int foo307_c389(int p, int q, int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 0) => (0 <= n@pre - n)) &&
((!(n@pre > 0)) => ((res == 0)&&(n == n@pre)&&(q == q@pre)&&(p == p@pre))) &&
(q == q@pre
          loop assigns n, p, res)
    */
    
            while (n > 0) {
            n -= 1;
            p *= 10;
            res = p / q;
            p %= q;
        }
        return res;
}