#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo366(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int count = 0;
       
  /*@ Inv
    (1 <= i) &&
    (0 <= count) &&
    (0 <= sum) &&
    (count <= i / 2) &&
    (2 * count <= i - 1) &&
    (i - 1 < 2 * (count + 1)) &&
    (sum == count * (count + 1)) &&
    (sum >= count)
    */
for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}