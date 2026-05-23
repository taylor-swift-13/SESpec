#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (pow5 : Z -> Z) */
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
    ((0 <= k@pre) => (0 <= c && c <= k@pre)) &&
    (0 <= y) &&
    (y == c) &&
    (x == sum5(c)) &&
    (forall (t:Z), 1 <= t && t <= c => pow5(t) >= 0) &&
    (c == 0 => x == 0) &&
    ((0 <= k@pre) => (c < k@pre => y < k@pre)) &&
    ((0 <= k@pre) => (y <= k@pre)) &&
    (x >= 0) &&
    ((0 <= k@pre) => (c == k@pre => (y == k@pre && x == sum5(k@pre)))) &&
    ((0 < k@pre) => (x == sum5(c))) &&
    ((0 < k@pre) => (0 <= y && y <= k@pre && y == c)) &&
    ((0 < k@pre) => (0 <= x && x <= sum5(c))) &&
    ((0 < k@pre) => (0 <= c && c <= k@pre)) &&
    ((!(0 < k@pre)) => ((c == 0)&&(x == 0)&&(y == 0)&&(k == k@pre))) &&
    (k == k@pre)
    */
    
    while(c < k){
      c = c + 1 ;
      y = y + 1;
      x=y*y*y*y*y+x;
    }

}