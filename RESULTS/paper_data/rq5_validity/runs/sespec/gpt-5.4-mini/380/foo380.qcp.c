#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (proper_divisor_sum : Z -> Z -> Z) */
int foo380(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (0 <= i) &&
    (0 <= sum) &&
    (number == number@pre) &&
    (sum <= (i - 1) * i / 2) &&
    (sum == proper_divisor_sum(number, i)) &&
    (forall (j:Z), 1 <= j && j < i && number % j == 0 => sum >= j) &&
    (exists (j:Z), 0 <= j && j < i => (j == 0 || j < i)) &&
    ((i <= number@pre / 2) => (sum >= 0)) &&
    ((i <= number@pre / 2) => (sum == proper_divisor_sum(number, i))) &&
    (number == number@pre)
    */
for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}