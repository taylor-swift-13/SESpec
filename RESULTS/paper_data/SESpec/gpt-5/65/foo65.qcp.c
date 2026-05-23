#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo65(int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int i;

    n = 0;
    i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i) &&
    (0 <= n) &&
    (n <= i + 1) &&
    (forall (t:Z), 0 <= t && t < i => (t % 2 == 0 => 2*(t/2) == t)) &&
    ((0 < 2 * k@pre) => (0 <= i && i <= 2 * k@pre)) &&
    ((!(0 < 2 * k@pre)) => ((i == 0)&&(n == 0)&&(k == k@pre))) &&
    (k == k@pre)
    */
    
    while (i < 2 * k) {
       if(i % 2 == 0){
         n = n + 1;
       }
       i = i + 1;
    }

  }