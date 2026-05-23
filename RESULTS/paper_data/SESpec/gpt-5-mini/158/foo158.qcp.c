#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo158(int n);

int foo158(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int *factors = (int *)malloc(sizeof(int) * (n));
int factors_len = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((j < n) => (forall (k:Z), 0 <= k && k < j => factors_l[k] == k + 1)) &&
((!(j < n)) => \true) &&
(forall (k:Z), 0 <= k && k < n =>
                            (k < j ? factors_l[k] == k + 1 : \true)
          loop assigns j, factors_l[0..n-1])
    */
    
            for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (\true ) &&
(forall (k:Z), 0 <= k && k < n => factors_l[k] == k + 1)
    */
    
            while (1) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
              loop invariant (0 <= a < n) ==>
                             ( (\exists integer b; 0 <= b < a && i % factors[b] != 0)
                               || (\forall integer b; 0 <= b < a ==> i % factors[b] == 0) );
              loop assigns a, i;
            */
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
            
        }
}