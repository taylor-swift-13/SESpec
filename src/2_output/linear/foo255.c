
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo255() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int v;

    v = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= v && v <= 51) &&
(v % 2 == 1
      loop assigns v)
    */
    
    while (v <= 50) {
        v = v + 2;
    }

    

  }