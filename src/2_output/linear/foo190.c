
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo190(int y) 

            /*@
            Require y > -1000 && y < 1000
            Ensure Results(__return)
            */
            {

    int x;

    x = -50;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y >= y@pre) &&
(y@pre > 0 => y > 0) &&
(y > y@pre || x == -50) &&
(y > 0 || x < 0
          loop assigns x, y)
    */
    
            while(x < 0){
       x = x + y;
       y = y + 1;
      }

    

  }