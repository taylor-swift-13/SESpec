#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo201(int n);

int foo201(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *A = (int *)malloc(sizeof(int) * (n+1));
int A_len = n+1;
        int *B = (int *)malloc(sizeof(int) * (n+1));
int B_len = n+1;
        A[0] = 1;
        A[1] = 0;
        B[0] = 0;
        B[1] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(int i = 2; i <= n; i++) {
            A[i] = A[i-2] + 2 * B[i-1];
            B[i] = A[i-1] + B[i-2];
        }
        return A[n];
}