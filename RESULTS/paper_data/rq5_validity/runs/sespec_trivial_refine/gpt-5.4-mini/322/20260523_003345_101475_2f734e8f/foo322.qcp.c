#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
int foo322(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int gcd = 1;
        int foo322 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
       
  /*@ Inv
    (1 <= i) &&
    (1 <= gcd) &&
    (divides(gcd, x) && divides(gcd, y)) &&
    (forall (k:Z), 1 <= k && k < i && divides(k, x) && divides(k, y) => k <= gcd)
    */
for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        foo322 = (x * y) / gcd;
        return foo322;
}