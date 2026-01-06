
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo120() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
 
    int i = 1;
    int sn = 0;
    
     
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i == sn + 1) &&
(sn == i - 1) &&
(1 <= i && i <= 9) &&
(0 <= sn && sn <= 8
      loop assigns i, sn)
    */
    
    while (i <= 8) {
        i = i + 1;
        sn = sn + 1;
    }
  
    
  
  }