#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo365(int n);

int foo365(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int count = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= i) &&
(sum == odd_sum_upto(i - 1)) &&
(count == odd_count_upto(i - 1)) &&
((i <= n@pre) => (sum == odd_sum_upto(i - 1)) ) &&
((i <= n@pre) => (count == odd_count_upto(i - 1)) ) &&
(n == n@pre
      loop assigns i, sum, count)
    */
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
            count++;
        }
    }
        return sum / count;
}