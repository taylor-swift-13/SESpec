
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo268(int n, int x, int y) 

            /*@
            Require x >= 0 && x <= y && y < n
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (\at(x, LoopEntry) <= x && x <= n) &&
(\at(y, LoopEntry) <= y && y <= n) &&
(y >= x - 1) &&
(y >= n - (n - x)
      loop assigns x, y)
    */
    
    while (x < n) {
       x = x + 1;
       if(x > y)
       y = y + 1;
    }

    

  }