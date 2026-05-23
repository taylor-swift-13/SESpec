#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (catalan_partial_sum : Z -> Z -> Z -> Z) */

int foo214(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
int catalan_len = num + 1;
        catalan[0] = 1;
       
  /*0*/ 
 /*@ Inv
    (PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS)
    */
for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
           
  /*1*/ 
 /*@ Inv
    (0 <= j && j <= i) &&
    (0 <= i && i <= num) &&
    (catalan[i] == catalan_partial_sum(catalan, i, j))
    */
for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
}