
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo254() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;

    x = 1;
    y = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= x && x <= 100) &&
((x <= 50 => y == x) && (x > 50 => y == 100 - x)
      loop assigns x, y)
    */
    
    while (y > 0) {
        if (x < 50) {
            y++;
        } else {
            y--;
        }
        x = x + 1;
    }

    

  }