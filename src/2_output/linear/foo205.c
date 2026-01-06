
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo205() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    y = x;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == y
      loop assigns x, y)
    */
    
    while(x < 1024) {
       x = x + 1;
       y = y + 1;
    }

    

  }