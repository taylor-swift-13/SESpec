#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (product : Z -> Z -> Z -> Z) */
int foo390(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 1;
        int i = 1;
       
  /*@ Inv
    (1 <= i) &&
    (i <= k + 1 || k < 1) &&
    ((1 <= k@pre) => (i >= 1 && i <= k + 1)) &&
    ((!(1 <= k@pre)) => ((i == 1) && (res == 1) && (k == k@pre) && (n == n@pre))) &&
    (k == k@pre) &&
    (n == n@pre)
    */
while (i <= k) {
        res *= (n - i + 1);
        i++;
    }
        return res;
}