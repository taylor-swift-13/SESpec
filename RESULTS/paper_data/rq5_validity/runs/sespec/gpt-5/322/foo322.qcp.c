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
    (gcd >= 1) &&
    (x <= y) &&
    ((x % gcd == 0) && (y % gcd == 0)) &&
    (forall (d:Z), 1 <= d && d < i => ((x % d == 0 && y % d == 0) => d <= gcd)) &&
    ((exists (d:Z), 2 <= d && d < i && x % d == 0 && y % d == 0) => (gcd >= 2)) &&
    (forall (d:Z), i <= d && d <= x => ((x % d == 0 && y % d == 0) => gcd <= d || gcd == 1)) &&
    ((i <= y@pre) => (gcd >= 1)) &&
    ((i <= y@pre) => ((foo322 == 1) && (gcd >= 1))) &&
    ((!(i <= y@pre)) => (foo322 == 1)) &&
    (foo322 == 1)
    */
for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        foo322 = (x * y) / gcd;
        return foo322;
}