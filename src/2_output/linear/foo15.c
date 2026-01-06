
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo15(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 0;
    int m = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= 0) &&
(x <= \max(0,n)) &&
(m >= 0) &&
(m < x || (x == 0 && m == 0)) &&
(m < n || n <= 0) &&
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