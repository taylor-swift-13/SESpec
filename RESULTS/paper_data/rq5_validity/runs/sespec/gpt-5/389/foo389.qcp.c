#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (power : Z -> Z -> Z) */
int foo389(int p, int q, int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
       
  /*@ Inv
    (q == q@pre) &&
    (n <= n@pre) &&
    ((n@pre <= 0) => (n == n@pre)) &&
    ((n > 0) => (n@pre > 0)) &&
    ((n > 0) => (n >= 1)) &&
    ((n <= 0) => (n == 0 || n@pre <= 0)) &&
    ((n@pre > 0) => (n >= 0)) &&
    ((n@pre > 0) => (res == res)) &&
    ((n@pre > 0) => (p == p)) &&
    ((n@pre > 0) => (n == n)) &&
    ((n@pre > 0) => (((res == 0)&&(n == n@pre)&&(q == q@pre)&&(p == p@pre)) || (n < n@pre))) &&
    ((!(n@pre > 0)) => ((res == 0)&&(n == n@pre)&&(q == q@pre)&&(p == p@pre)))
    */
while (n > 0) {
    n -= 1;
    p *= 10;
    res = p / q;
    p %= q;
  }
        return res;
}