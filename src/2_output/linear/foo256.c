
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo256() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int v;

    v = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (exists (k:Z), 0 <= k && v == 1 + 2*k && v <= 51
      loop assigns v)
    */
    
    while (v <= 50) {
        v = v + 2;
    }

    

  }