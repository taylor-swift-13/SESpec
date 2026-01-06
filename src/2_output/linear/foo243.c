
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo243() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;
    unsigned int y;

    y = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((y == 0) => (x % 3 == 0)
      loop assigns x, y)
    */
    
    while(unknown()) {
       if(x % 3 == 1) {
           x = x + 2;
           y = 0;
       }
       else {
           if(x % 3 == 2) {
               x = x + 1;
               y = 0;
           }
           else {
               if(unknown()) {
                   x = x + 4;
                   y = 1;
               }
               else {
                   x = x + 5;
                   y = 1;
               }
           }
       }
    }

    

  }