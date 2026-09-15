#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo385(int n, int m);

int foo385(int n, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (m == m@pre) &&
(n == n@pre) &&
(i <= n) &&
(no_divisible_in_range(n, i, m)) &&
((!(i >= 0)) => ((m == m@pre)&&(n == n@pre))) &&
(m == m@pre) &&
(n == n@pre
      loop assigns i)
    */
    
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }
        return -1;
}