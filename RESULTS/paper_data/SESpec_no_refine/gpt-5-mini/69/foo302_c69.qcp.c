#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo302_c69(unsigned int n) 
/*@

Require emp
Ensure emp
*/{

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (l == i + j + k)) &&
((0 < n@pre) => (k == l - i - j)) &&
((!(0 < n@pre)) => ((l == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns i, j, k, l)
    */
    
            while (l < n) {
       if ((l % 3) == 0) {
       i = i + 1;
      }
       else if((l % 2) == 0){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }

  }