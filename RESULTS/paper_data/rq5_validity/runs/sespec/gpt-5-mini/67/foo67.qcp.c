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
    (0 <= i && 0 <= j && 0 <= k) &&
    (i % 3 == 0) &&
    (j % 3 == 0) &&
    (k % 3 == 0) &&
    (j + k == i) &&
    ((forall (t:Z), 0 <= t && t < i => 0 <= t + 1)) &&
    ((0 < n@pre) => (i >= 0 && j >= 0 && k >= 0)) &&
    ((0 < n@pre) => (j + k == i)) &&
    ((0 < n@pre) => (0 <= i && i <= n + 2)) &&
    ((0 < n@pre) => (0 <= j && 0 <= k)) &&
    ((0 < n@pre) => (j <= i)) &&
    ((0 < n@pre) => (k <= i)) &&
    ((!(0 < n@pre)) => ((j == 0) && (k == 0) && (i == 0) && (n == n@pre))) &&
    (n == n@pre)
    */
    
    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
         j = j + 3;
       else
         k = k + 3;
    }

  }