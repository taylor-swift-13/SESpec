
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo18(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 1;
    int m = 1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 < n@pre) => (x >= 1 && x <= n)) &&
((1 < n@pre) => (((m == 1)&&(x == 1)&&(n == n@pre)) || (m >= 1 && m <= x-1))) &&
((!(1 < n@pre)) => ((m == 1)&&(x == 1)&&(n == n@pre))) &&
(n == n@pre
      loop assigns x, m)
    */
    
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
 
    

}