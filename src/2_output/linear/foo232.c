
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo232(unsigned int y) 

            /*@
            Require y > 2
            Ensure Results(__return)
            */
            {

    unsigned int x;
    unsigned

    x = 2;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= x && x <= y) &&
((x < y / x) => (x * x <= y)
      loop assigns x)
    */
    
    while (x < y) {
        if (x < y / x) {
            x *= x;
        }
        else {
            x++;
        }
    }

    

  }