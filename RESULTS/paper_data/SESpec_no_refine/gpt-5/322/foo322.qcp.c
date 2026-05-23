#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo322(int x, int y);

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
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (foo322 == 1) &&
(forall (d:Z), 1 <= d && d < i => (d <= x && d <= y && x % d == 0 && y % d == 0) => gcd >= d
          loop assigns i, gcd)
    */
    
            for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        foo322 = (x * y) / gcd;
        return foo322;
}