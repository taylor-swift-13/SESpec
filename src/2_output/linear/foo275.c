
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo275(int x, int y) 

            /*@
            Require y > 0 || x > 0
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre + y@pre <= -2) => (x >= x@pre && y >= y@pre)) &&
((x@pre + y@pre <= -2) => (x > 0 || y > 0)) &&
((!(x@pre + y@pre <= -2)) => ((y == y@pre)&&(x == x@pre))
          loop assigns x, y)
    */
    
            while (x + y <= -2) {
       if (x > 0) {
       x++;
      }
       else {
       y++;
      }
      }

    

  }