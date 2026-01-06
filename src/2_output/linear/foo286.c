
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo286(int x, int y, int z) 

            /*@
            Require x == y && x >= 0 && x + y + z == 0
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre > 0) => (x == x@pre - x@pre + x && x >= 0 && x + y + z == 0)) &&
((x@pre > 0) => (y == y@pre - y@pre + y && y == x)) &&
((x@pre > 0) => (z == z@pre + 2*(x@pre - x))) &&
((!(x@pre > 0)) => ((z == z@pre)&&(y == y@pre)&&(x == x@pre))
        loop assigns x, y, z)
    */
    
    while (x > 0) {
       x--;
       y--;
       z += 2;
    }

    

  }