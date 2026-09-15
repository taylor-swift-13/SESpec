#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo312_c390(int n, int k);

int foo312_c390(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 1;
        int i = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= k@pre) => (1 <= i && i <= k@pre + 1)) &&
((1 <= k@pre) => ((i-1) <= k@pre)) &&
((!(1 <= k@pre)) => ((i == 1)&&(res == 1)&&(k == k@pre)&&(n == n@pre))) &&
(k == k@pre) &&
(n == n@pre
      loop assigns res, i)
    */
    
    while (i <= k) {
        res *= (n - i + 1);
        i++;
    }
        return res;
}