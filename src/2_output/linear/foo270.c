
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo270(int y) 

            /*@
            Require y >= 0
            Ensure Results(__return)
            */
            {

    int x;

    x = y;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((y@pre != 0) => (y == x)) &&
((y@pre != 0) => (x >= 0 && y >= 0)) &&
((!(y@pre != 0)) => ((x == y@pre)&&(y == y@pre))
    loop assigns x, y)
    */
    
    while (x != 0) {
       x = x - 1;
       y = y - 1;
    }

    

  }