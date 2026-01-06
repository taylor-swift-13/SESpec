
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo276() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    i = 0;
    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i >= 0 && i <= 100) &&
(j == 2 * i
      loop assigns i, j)
    */
    
    while (i < 100) {
       j += 2;
       i++;
    }

    

  }