#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
int foo323(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
        if (n == 1) return 1;
       
  /*@ Inv
    (2 <= i) &&
    (count >= 0) &&
    (count <= i - 2) &&
    (forall (d:Z), 2 <= d && d < i => (divides(n,d) <=> (n % d == 0))) &&
    (forall (d:Z), 2 <= d && d < i => (divides(n,d) => (n / d != d))) &&
    ((i <= n / i) => (2 <= i))
    */
for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
}