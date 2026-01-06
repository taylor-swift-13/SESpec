
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo271(int x, int y) 

            /*@
            Require x != y
            Ensure Results(__return)
            */
            {

    int t;

    y = t;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y >= t
          loop assigns y)
    */
    
            while (unknown()) {
       if(x > 0)
       y = y + x;
      }

    

  }