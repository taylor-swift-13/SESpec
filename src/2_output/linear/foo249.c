
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo249(int k) 

            /*@
            Require k >= 0 && k <= 1
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    i = 1;
    j = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (k == k@pre - (i - 1)) &&
(i == 1 + (k@pre - k)) &&
(j == 1 + (k@pre * (i - 1) - (i - 1) * (i - 2) / 2)
          loop assigns i, j, k)
    */
    
            while (unknown()) {
       i = i + 1;
       j = j + k;
       k = k - 1;
      }

    

  }