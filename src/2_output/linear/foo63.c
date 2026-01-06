
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo63(int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 1;
    
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((x == 1)&&(y == y@pre)) || (y == 10 - (x - 1))) &&
(1 <= x && x <= 11)
    */
    
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }

    

}