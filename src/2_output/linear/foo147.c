
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo147() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int xa;
    int ya;

    xa = 0;
    ya = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((ya == 0)&&(xa == 0)) || (xa == x - y * 2)) &&
(((ya == 0)&&(xa == 0)) || (ya == x * 2 + y)
      loop assigns x, y, xa, ya)
    */
    
    while(unknown()) {
       x = xa + ya * 2 + 1;
       if(unknown()) {
         y = ya - xa * 2 + x;
       }
       else {
         y = ya - xa * 2 - x;
       }
       xa = x - y * 2;
       ya = x * 2 + y;
    }

  }