#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo68(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (l <= n@pre)) &&
((0 < n@pre) => (i + j == l)) &&
((0 < n@pre) => (i == (l + 1) / 2)) &&
((0 < n@pre) => (j == l / 2)) &&
((!(0 < n@pre)) => ((l == 0)&&(i == 0)&&(j == 0)&&(n == n@pre))) &&
(n == n@pre
      loop assigns i, j, l)
    */
    
    while (l < n) {
       if ((l % 2) == 0) {
         i = i + 1;
       }
       else{
         j = j + 1;
       }
       l = l + 1;
    }

  }