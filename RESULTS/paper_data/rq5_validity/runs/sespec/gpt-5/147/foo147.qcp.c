#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo147(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int temp = n;
       
  /*@ Inv
    (n == n@pre) &&
    ((!(n@pre != 0 && n@pre % 3 == 0)) => (temp == n@pre)) &&
    ((n@pre != 0 && n@pre % 3 == 0) => (temp != 0)) &&
    ((n@pre != 0 && n@pre % 3 == 0) => ( (temp != 0 && temp % 3 == 0) => (temp/3 == temp / 3) )) &&
    ((n@pre != 0 && n@pre % 3 == 0) => ( (temp == 0 || temp % 3 != 0) => (temp == temp) )) &&
    ((n@pre != 0 && n@pre % 3 == 0) => (temp == 0 || temp % 3 == 0 || temp % 3 != 0))
    */
while (temp != 0 && temp % 3 == 0) {
        temp /= 3;
    }
        return temp == 1;
}