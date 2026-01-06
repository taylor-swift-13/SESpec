
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo100(int n) 

            /*@
            Require n>=0
            Ensure Results(__return)
            */
            {

    int x = n;
    int y = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 0) => (x + y == n@pre)) &&
((n@pre > 0) => (x >= 0 && y >= 0)) &&
((!(n@pre > 0)) => ((y == 0)&&(x == n@pre)&&(n == n@pre))) &&
(n == n@pre
        loop assigns x, y)
    */
    
    while (x > 0) {
        y = y + 1;
        x = x - 1;
    }
  
    
  
  }