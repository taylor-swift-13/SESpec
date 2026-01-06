
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo222(int w, int x, int y, int z) 

            /*@
            Require x > 0 && y > 0 && z > 0 && w > 0
            Ensure Results(__return)
            */
            {


    x = w;
    z = x + 1;
    y = w + 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y == z) &&
(y == w@pre + 1 + (\at(y,Here) - \at(y,LoopEntry))) &&
(z == w@pre + 1 + (\at(z,Here) - \at(z,LoopEntry))) &&
(x == w@pre) &&
(w == w@pre
          loop assigns y, z)
    */
    
            while (unknown()) {
       y = y + 1;
       z = z + 1;
      }

  }