
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo202(int x) 

            /*@
            Require x <= 1 && x >= 0
            Ensure Results(__return)
            */
            {

    int y;

    y = -3;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x <= x@pre) &&
(y >= -3
          loop assigns x, y)
    */
    
            while(unknown()){
       if(x - y < 2){
       x = x - 1;
       y = y + 2;
      }
       else if(x - y >= 2){
       y = y + 1;
      }
      }

    

  }