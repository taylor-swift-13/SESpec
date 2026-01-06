
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo289(int x, int y) 

            /*@
            Require x < y && y <= 20000001
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre < y@pre) => (x >= x@pre && y >= y@pre - 10*(x - x@pre)/7)) &&
((x@pre < y@pre) => (x - y <= (x@pre - y@pre) + 17*(x - x@pre)/7)) &&
((x@pre < y@pre) => (x - y <= 16)) &&
((!(x@pre < y@pre)) => ((y == y@pre)&&(x == x@pre))
          loop assigns x, y)
    */
    
        while (x < y) {
            if ((x < 0 && y < 0)){
                x = x + 7;
                y = y - 10;
            }
            else if ((x < 0 && y >= 0)){
                x = x + 7;
                y = y + 3;
            }
            else {
                x = x + 10;
                y = y + 3;
            }
        }

    

  }