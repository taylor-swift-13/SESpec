
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo27(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = n;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 1) => (x >= 1 && x <= n@pre)) &&
((!(n@pre > 1)) => ((x == n@pre) && (n == n@pre))) &&
(n == n@pre
      loop assigns x)
    */
    
    while (x > 1) {
        x = x - 1;
    }
  
   
  }