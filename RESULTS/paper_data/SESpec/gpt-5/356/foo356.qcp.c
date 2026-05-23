#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo356(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
        int count = 0;
        int temp = n;
       
  /*@ Inv
    (0 <= count) &&
    (temp == n@pre >> count) &&
    ((n@pre >= 0) => (0 <= temp && temp <= n@pre)) &&
    ((temp == 0) => (n@pre >> count == 0)) &&
    ((n@pre > 0) => (0 <= count)) &&
    ((n@pre > 0) => (temp == n@pre >> count)) &&
    ((!(n@pre > 0)) => ((temp == n@pre)&&(count == 0)&&(res == 0)&&(n == n@pre))) &&
    (n == n@pre)
    */
while (temp > 0) {
            if (count % 2 == 0) {
                res = res | (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return n ^ res;
}