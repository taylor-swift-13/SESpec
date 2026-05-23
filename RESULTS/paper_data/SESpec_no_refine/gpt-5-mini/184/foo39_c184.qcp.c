#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo39_c184(int n);

int foo39_c184(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
int sumOfPrimeDivisors_len = n + 1;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
               
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
}