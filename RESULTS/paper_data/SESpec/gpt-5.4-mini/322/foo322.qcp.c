#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    ((i <= x + 1) || (x < 0)) &&
    (gcd >= 1) &&
    (gcd <= i) &&
    (foo322 == 1) &&
    (gcd == 1 || (x % gcd == 0 && y % gcd == 0)) &&
    (forall (k:Z), 1 <= k && k < i && x % k == 0 && y % k == 0 => k <= gcd) &&
    (gcd == 1 || (exists (k:Z), 1 <= k && k < i && x % k == 0 && y % k == 0 && gcd == k))
    */
for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        foo322 = (x * y) / gcd;
        return foo322;
}