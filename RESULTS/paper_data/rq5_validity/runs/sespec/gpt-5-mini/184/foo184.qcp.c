#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo184(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
int sumOfPrimeDivisors_len = n + 1;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

       
  /*0*/ 
 /*@ Inv
    (2 <= i && i <= n + 1) &&
    (1 <= j && j <= n) &&
    (true)) &&
    (forall (k:Z), 0 <= k && k < i => sumOfPrimeDivisors[k] >= 0) &&
    (forall (k:Z), 0 <= k && k < i => sumOfPrimeDivisors[k] == sumOfPrimeDivisors[k])
    */
for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
               
  /*1*/ 
 for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
}