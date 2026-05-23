#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo389(int p, int q, int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
       
  /*@ Inv
    (n >= 0) &&
    (p >= 0) &&
    (q > 0) &&
    (n <= n@pre) &&
    ((n@pre > 0) => (p >= 0)) &&
    ((n@pre > 0) => (n >= 0)) &&
    ((!(n@pre > 0)) => ((res == 0) && (n == n@pre) && (q == q@pre) && (p == p@pre))) &&
    (q == q@pre)
    */
while (n > 0) {
        n -= 1;
        p *= 10;
        res = p / q;
        p %= q;
    }
        return res;
}