
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo227() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x % 2) == (y % 2) || x < 99) &&
(y % 2 == 0 => x % 10 == 0) &&
(y % 2 != 0 => x % 5 == 0)
    */
    
            while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
      }

    

  }