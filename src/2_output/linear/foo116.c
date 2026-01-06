
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo116(int v1,int v2,int v3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int sn = 0;
    int x = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (sn == x) &&
(x >= 0) &&
(sn >= 0) &&
(v3 == v3@pre) &&
(v2 == v2@pre) &&
(v1 == v1@pre
      loop assigns sn, x)
    */
    
    while (unknown()) {
        x = (x + 1);
        sn = (sn + 1);
    }
       
      
    
  
  }