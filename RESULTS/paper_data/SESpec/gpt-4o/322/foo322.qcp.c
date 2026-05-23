#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (gcd_logic : Z -> Z -> Z) */
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
    (1 <= i && i <= x + 1) &&
    (forall (k:Z), 1 <= k && k < i => (x % k == 0 && y % k == 0 => gcd >= k)) &&
    (gcd_logic(x, y) == gcd_logic(x, y)) &&
    (foo322 == 1) &&
    (y == x@pre || y == y@pre) &&
    (x == y@pre || x == x@pre)
    */
for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }
        foo322 = (x * y) / gcd;
        return foo322;
}