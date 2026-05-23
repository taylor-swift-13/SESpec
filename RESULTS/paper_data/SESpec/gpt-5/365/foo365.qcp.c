#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo365(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int count = 0;
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= count && count <= i - 1) &&
    (0 <= sum) &&
    (count == i / 2) &&
    (sum == count * count) &&
    ((i % 2 == 0) => (i == 2 * count)) &&
    ((i % 2 != 0) => (i == 2 * count + 1)) &&
    (count == 0 <=> i == 1) &&
    (i <= n => count <= n / 2) &&
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