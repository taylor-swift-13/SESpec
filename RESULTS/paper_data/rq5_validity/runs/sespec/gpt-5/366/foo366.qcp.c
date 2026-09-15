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
    (sum >= 0 && count >= 0) &&
    (count == ((i - 1) / 2)) &&
    (sum == ((i - 1) / 2) * (((i - 1) / 2) + 1)) &&
    ((i == n + 1) => (count == (n / 2))) &&
    ((i == n + 1) => (sum == (n / 2) * ((n / 2) + 1))) &&
    ((i <= n@pre) => (i >= 1 && i <= n@pre)) &&
    ((i <= n@pre) => (sum == ((i - 1) / 2) * (((i - 1) / 2) + 1))) &&
    ((i <= n@pre) => (count == ((i - 1) / 2))) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}