#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_count : Z -> Z) */
/*@ Extern Coq (odd_sum : Z -> Z) */
int foo365(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int count = 0;
       
  /*@ Inv
    (i >= 1) &&
    (0 <= count) &&
    (0 <= sum) &&
    (count == i / 2) &&
    (sum == count * count) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}