#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo86(int k)
/*@

Require emp
Ensure emp
*/{

    int y=0;
    int x=0;
    int c=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x) &&
    (y == c) &&
    (x >= c) &&
    (x >= y) &&
    (c == 0 => x == 0) &&
    (c == 0 => y == 0) &&
    (c > 0 => x >= c*c) &&
    (c > 0 => y > 0) &&
    (c == k@pre => !(c < k@pre)) &&
    ((0 < k@pre) => (c <= k@pre)) &&
    ((0 < k@pre) => (c <= y && y <= k@pre)) &&
    ((0 < k@pre) => (x >= c && x >= y)) &&
    ((0 < k@pre) => (c < k@pre => y < k@pre)) &&
    ((0 < k@pre) => (c < k@pre => x < (k@pre+1)*(k@pre+1) + x)) &&
    ((0 < k@pre) => (y == c)) &&
    ((0 < k@pre) => (0 <= x)) &&
    ((0 < k@pre) => (0 <= c && c <= k@pre)) &&
    ((!(0 < k@pre)) => ((c == 0)&&(x == 0)&&(y == 0)&&(k == k@pre))) &&
    (k == k@pre)
    */
    
    while(c < k){
        c = c + 1;
        y = y + 1;
        x = y * y + x;
    }

}