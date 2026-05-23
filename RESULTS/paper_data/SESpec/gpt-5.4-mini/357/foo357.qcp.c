#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (oddmask : Z -> Z) */
int foo357(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
        int res = 0;
        int temp = n;
       
  /*@ Inv
    (count >= 0) &&
    (res == oddmask(count)) &&
    (n == n@pre) &&
    (temp <= n@pre) &&
    ((n@pre >= 0) => (temp >= 0)) &&
    ((n@pre >= 0) => (temp == (n@pre >> count))) &&
    ((n@pre >= 0) => (res == oddmask(count))) &&
    ((n@pre >= 0) => (count + temp <= n@pre)) &&
    ((!(n@pre > 0)) => (temp == n@pre && res == 0 && count == 0 && n == n@pre))
    */
while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
}