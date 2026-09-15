#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_factor_array : Z -> Z -> Prop) */

/*@ Extern Coq (factors_initialized : Z -> Z -> Prop) */
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
       
  /*@ Inv
    (0 <= j && j <= n) &&
    (forall (k:Z), 0 <= k && k < j => factors[k] == k + 1)
    */
for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
       
  /*@ Inv
    emp
    */
while (1) {
            
            
        /*@
          loop invariant 0 <= a <= n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
          loop invariant \forall integer k; 0 <= k < a ==> i % factors[k] == 0;
          loop assigns a, i;
        */
            /*@ Inv
    (0 <= a && a <= n) &&
    (forall (k:Z), 0 <= k && k < n => factors[k] == k + 1) &&
    (forall (k:Z), 0 <= k && k < a => i % factors[k] == 0)
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