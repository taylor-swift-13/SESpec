#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (ipow : Z -> Z -> Z) */
/*@ Extern Coq (geom_sum : Z -> Z -> Z) */

void foo83(int z,int k,int a)
/*@

Require emp
Ensure emp
*/{

    int x=a;
    int y=1;
    int c=1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (geom_sum(z, c) == (c <= 0 ? 0 : geom_sum(z, c - 1) * z + 1)) &&
    (ipow(z, c - 1) == ((c - 1) <= 0 ? 1 : z * ipow(z, (c - 1) - 1))) &&
    ((c == 1) => (x == a && y == 1)) &&
    ((c > 1) => (y == ipow(z, c - 2) * z)) &&
    ((1 < k@pre) => ( (c == 1) => (x == a && y == 1) )) &&
    ((1 < k@pre) => ( y == ipow(z, c - 1) )) &&
    ((1 < k@pre) => ( 1 <= c && c <= k@pre )) &&
    ((!(1 < k@pre)) => ((c == 1)&&(y == 1)&&(x == a@pre)&&(a == a@pre)&&(k == k@pre)&&(z == z@pre))) &&
    (a == a@pre) &&
    (k == k@pre) &&
    (z == z@pre)
    */
    
    while (c < k){
      c = c + 1;
      x = x*z + a;
      y = y*z;
    }

  }