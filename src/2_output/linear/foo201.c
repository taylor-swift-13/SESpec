
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo201(int x) 

            /*@
            Require x <= -2 && x >= -3
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= -3 && (x == -3 || x == -2 || x == -1 || x == 0 || x == 1 || x % 1 == 0)
          loop assigns x)
    */
    
        while(unknown()){
            if(x < 1){
                x = x + 2;
            }
            else if(x >= 1){
                x = x + 1;
            }
        }

    

  }