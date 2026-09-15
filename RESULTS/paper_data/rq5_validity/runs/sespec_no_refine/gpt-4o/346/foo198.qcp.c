#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo198(int n);

int foo198(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (forall (k:Z), 2 <= k && k < i => (n % k != 0 || max >= k)
      loop assigns i, max, n)
    */
    
    for (int i = 2; i <= n; i++) {
        
        /*@
          loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || max >= k);
          loop assigns i, max, n;
        */
        while (n % i == 0) {
            max = i;
            n /= i;
        }
        
    }
        return max;
}