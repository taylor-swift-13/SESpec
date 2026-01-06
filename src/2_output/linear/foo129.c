
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo129(int y,int z1,int z2,int z3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 1;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(1 < y@pre)) => ((x == 1)&&(z3 == z3@pre)&&(z2 == z2@pre)&&(z1 == z1@pre)&&(y == y@pre))) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre) &&
(y == y@pre
      loop assigns x)
    */
    
    while (x < y) {
        x = x + x;
    }
  
    
  
  }