
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo207(int y) 

            /*@
            Require y <= 1000000
            Ensure Results(__return)
            */
            {

    int x;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y == y@pre
        loop assigns x)
    */
    
    while(x < 100 && y > 0) {
        x = x + y;
    }

    

  }