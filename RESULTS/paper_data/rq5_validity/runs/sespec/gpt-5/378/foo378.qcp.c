#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_sum_from_to : Z -> Z -> Z) */
int foo378(int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (l == l@pre) &&
    (r == r@pre) &&
    ((l <= r) => (l <= i && i <= r + 1)) &&
    ((l > r) => (i == l)) &&
    ((l <= r) => (sum == odd_sum_from_to(l, i - 1))) &&
    ((l > r) => (sum == 0)) &&
    ((i == l) => (sum == 0)) &&
    ((i <= r@pre) => (l <= i && i <= r)) &&
    ((i <= r@pre) => (sum == odd_sum_from_to(l, i - 1))) &&
    ((!(i <= r@pre)) => ((r == r@pre)&&(l == l@pre))) &&
    (r == r@pre) &&
    (l == l@pre)
    */
for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
}