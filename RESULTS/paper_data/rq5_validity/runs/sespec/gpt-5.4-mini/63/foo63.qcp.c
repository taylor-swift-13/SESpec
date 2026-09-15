#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo63() 
/*@

Require emp

Ensure emp
*/{

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= a) &&
    (0 <= b) &&
    (0 <= i) &&
    (1 <= j) &&
    (i == 2 * a) &&
    (j == i + 1) &&
    (b == a) &&
    (i % 2 == 0) &&
    (j % 2 == 1) &&
    (a == b) &&
    (a <= i) &&
    (b <= i) &&
    (j > i) &&
    (exists (k:Z), 0 <= k && k <= a && i == 2 * k) &&
    (exists (k:Z), 0 <= k && k <= a && j == 2 * k + 1) &&
    (exists (k:Z), 0 <= k && k <= a && b == k)
    */
    
            while (unknown()) {
       a = a + 1;
       b = b + j - i;
       i = i + 2;
       if (i % 2 == 0){
       j = j + 2;
      }
       else{
       j = j + 1;
      }
      }

  }