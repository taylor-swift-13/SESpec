#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo67(int n) 
/*@

Require emp
Ensure emp
*/{

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i) &&
    (0 <= j && j <= i) &&
    (0 <= k && k <= i) &&
    (j + k == i) &&
    (i % 3 == 0) &&
    (j % 3 == 0) &&
    (k % 3 == 0) &&
    (i == j + k) &&
    (0 <= i) &&
    ((i < n) => (j + k < n + 2)) &&
    ((i >= n) => (j + k >= n))
    */
    
    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
       j = j + 3;
       else
       k = k + 3;
    }

  }