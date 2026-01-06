
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo93(int n) 

            /*@
            Require n >= 0
            Ensure Results(__return)
            */
            {
  
    int i = 0;
    int x = 0;
    int y = 0;
    
  
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (x + y == 3 * i)) &&
((0 < n@pre) => (i <= n)) &&
((0 < n@pre) => (x >= 0 && y >= 0)) &&
((!(0 < n@pre)) => ((y == 0) && (x == 0) && (i == 0) && (n == n@pre))) &&
(n == n@pre
        loop assigns i, x, y)
    */
    
    while (i < n) {
        i = i + 1;
        if (unknown()) {
            x = x + 1;
            y = y + 2;
        } else {
            x = x + 2;
            y = y + 1;
        }
    }
  
    
  
  }