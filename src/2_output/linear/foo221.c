
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo221(int w, int x, int y, int z) 

            /*@
            Require x > 0 && y > 0 && z > 0 && w > 0
            Ensure Results(__return)
            */
            {


    x = w;
    z = y;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (w == x) &&
(x >= w@pre) &&
(y == z) &&
(z <= y@pre)
    */
    
            while(unknown()) {
       if (unknown()) {
       w = w + 1;
       x = x + 1;
      }
       else {
       y = y - 1;
       z = z - 1;
      }
      }

    

  }