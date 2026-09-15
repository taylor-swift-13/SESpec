#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
int foo346(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Inv
    (2 <= i) &&
    (0 <= max) &&
    (n <= n@pre)
    */
for (int i = 2; i <= n; i++) {
        
            /*@
              loop invariant 2 <= i;
              loop invariant 0 <= max;
              loop invariant n <= \at(n,Pre);
              loop assigns max, n;
            */
            /*@ Inv
    (2 <= i) &&
    (0 <= max) &&
    (n <= n@pre) &&
    ((n % i == 0) => (i != 0 && divides(i, n)))
    */
while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
        return max;
}