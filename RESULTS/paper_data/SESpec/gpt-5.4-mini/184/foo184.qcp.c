#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo184(int n);

int foo184(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
int sumOfPrimeDivisors_len = n + 1;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i >= 2
          loop assigns i, sumOfPrimeDivisors_l[0 .. n])
    */
    
            for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                
            
            /*@
              loop invariant i <= j <= n + i;
              loop invariant j >= i;
              
              loop assigns j, sumOfPrimeDivisors[0 .. n];
              loop variant ((n - j) / i) + 1;
            */
            for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            
            }
        }

        return sumOfPrimeDivisors[n];
}