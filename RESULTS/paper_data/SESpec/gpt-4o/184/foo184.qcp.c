#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (is_prime : Z -> Prop) */

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
    (forall (k:Z), 2 <= k && k < i => (is_prime(k) => sumOfPrimeDivisors[k] == k) && (!is_prime(k) => sumOfPrimeDivisors[k] == (\sum int d 1 <= d && d <= k && k % d == 0 && is_prime(d) d)))
    */
for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
               
  /*1*/ 
 /*@ Inv
    (i <= j && j <= n + 1) &&
    (forall (k:Z), i <= k && k < j => sumOfPrimeDivisors[k] == (\sum int d 1 <= d && d <= k && k % d == 0 && is_prime(d) d))
    */
for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
}