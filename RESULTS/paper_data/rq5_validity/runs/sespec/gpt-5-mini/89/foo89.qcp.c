#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum5 : Z -> Z) */

void foo89(int k)
/*@

Require emp
Ensure emp
*/{

    int y=0;
    int x=0;
    int c=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= c) &&
    ((k < 0) || (c <= k)) &&
    (0 <= y <= (k < 0 ? 0 : k)) &&
    (0 <= x) &&
    ((y == c)) &&
    (x == sum5(y)) &&
    (x * 12 == (y*y) * ((y + 1)*(y + 1)) * (2*y*y + 2*y - 1) => (y >= 0)) &&
    ((0 < k@pre) => (c <= k@pre)) &&
    ((0 < k@pre) => (y <= k@pre)) &&
    ((0 < k@pre) => (x >= 0)) &&
    ((0 < k@pre) => (c == y)) &&
    ((!(0 < k@pre)) => ((c == 0)&&(x == 0)&&(y == 0)&&(k == k@pre))) &&
    (k == k@pre)
    */
    
    while(c < k){
        c = c + 1 ;
        y = y + 1;
        x=y*y*y*y*y+x;
    }

}