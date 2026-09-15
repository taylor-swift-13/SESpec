#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo156(int i, int j, int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int b;

    n = 0;
    b = 1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(0 < (2 * k@pre))) => ((b == 1)&&(n == 0)&&(k == k@pre)&&(j == j@pre)&&(i == i@pre))) &&
(k == k@pre
      loop assigns n, b, i, j)
    */
    
    while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
           b = 0;
           i = i + 1;
       }
       else{
           b = 1;
           j = j + 1;
       }
    }

  }