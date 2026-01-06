
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo131(int x2,int x3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int d1 = 1;
    int d2 = 1;
    int d3 = 1;
    int x1 = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x1 >= 0) &&
(x3 >= 0 || x1 == 1) &&
(x3 <= x3@pre) &&
(d3 == 1) &&
(d2 == 1) &&
(d1 == 1
          loop assigns x1, x2, x3)
    */
    
            while(x1 > 0) {
        if(x2 > 0) {
            if(x3 > 0) {
                x1 = x1 - d1;
                x2 = x2 - d2;
                x3 = x3 - d3;
            }
        }
    }

    


}