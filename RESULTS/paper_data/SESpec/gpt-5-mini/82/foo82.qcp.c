#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (power : Z -> Z -> Z) */

void foo82(int z,int k)
/*@

Require emp
Ensure emp
*/{

    int x=1;
    int y=1;
    int c=1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c && c <= k) &&
    (0 <= x) &&
    (0 <= y) &&
    (y == power(z, (c - 1))) &&
    (forall (i:Z), 1 <= i && i < c => power(z, (i - 1)) >= 0) &&
    (x >= 1) &&
    ((1 < k@pre) => (c <= k@pre)) &&
    ((1 < k@pre) => (y == power(z@pre, (c - 1)))) &&
    ((1 < k@pre) => (c >= 1)) &&
    ((!(1 < k@pre)) => ((c == 1) && (y == 1) && (x == 1) && (k == k@pre) && (z == z@pre))) &&
    (k == k@pre) &&
    (z == z@pre)
    */
    
    while (c < k){
       c = c + 1;
       x = x*z + 1;
       y = y*z;
    }

  }