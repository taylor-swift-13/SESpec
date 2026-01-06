
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo237() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int i;
    unsigned int j;
    unsigned int k;

    i = 0;
    j = 0;
    k = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (k == i + j) &&
(j == 2 * i) &&
(k == 3 * i
      loop assigns i, j, k)
    */
    
    while (k < 268435455) {
        i = i + 1;
        j = j + 2;
        k = k + 3;
    }

    

  }