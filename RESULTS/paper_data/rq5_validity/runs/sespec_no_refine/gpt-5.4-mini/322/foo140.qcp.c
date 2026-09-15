#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo140(int x, int y);

int foo140(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int gcd = 1;
        int foo140 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((i <= y@pre) => (((foo140 == 1)&&(gcd == 1)&&(y == x@pre)&&(x == y@pre)) || (PLACE_HOLDER_gcd(x,y)))) &&
(foo140 == 1
          loop assigns i, gcd)
    */
    
            for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        foo140 = (x * y) / gcd;
        return foo140;
}