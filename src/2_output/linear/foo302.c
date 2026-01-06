
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo302() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i % 4 == 0 && i >= 0 && i <= 50000001 + 8
      loop assigns i)
    */
    
    while(i < 50000001) {
       if(unknown())
           i = i + 8;
       else
           i = i + 4;
    }

    

  }