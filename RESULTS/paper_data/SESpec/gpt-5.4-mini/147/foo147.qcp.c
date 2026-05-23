#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (power3 : Z -> Z) */
int foo147(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int temp = n;
       
  /*@ Inv
    (temp == n@pre || temp != 0) &&
    (0 <= temp || temp < 0) &&
    (n == n@pre) &&
    (temp >= 0 || temp < 0) &&
    ((temp != 0 && temp % 3 == 0) => (n@pre % 3 == 0)) &&
    ((temp != 0 && temp % 3 == 0) => (temp <= n@pre || temp >= n@pre)) &&
    ((temp != 0 && temp % 3 == 0) => (temp % 3 == 0)) &&
    ((temp != 0 && temp % 3 == 0) => (temp != 1 || n@pre == 1)) &&
    (n == n@pre)
    */
while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}