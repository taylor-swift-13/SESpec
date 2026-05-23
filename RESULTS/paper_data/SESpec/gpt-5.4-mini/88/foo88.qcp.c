#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fourth_sum : Z -> Z) */

void foo88(int k)
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
    (c == y) &&
    (x == fourth_sum(c)) &&
    ((0 < k@pre) => (c <= k@pre)) &&
    ((0 < k@pre) => (x == fourth_sum(c) && c == y && 0 <= c && c <= k@pre)) &&
    ((0 < k@pre) => (c == y)) &&
    ((0 < k@pre) => (x == fourth_sum(c))) &&
    ((0 < k@pre) => (0 <= c && c <= k@pre)) &&
    ((!(0 < k@pre)) => ((c == 0)&&(x == 0)&&(y == 0)&&(k == k@pre))) &&
    (k == k@pre)
    */
    
            while(c < k){
     c = c +1 ;
     y = y +1;
     x = y*y*y*y+x;
    }

}