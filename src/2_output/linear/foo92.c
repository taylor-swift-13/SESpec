
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo92(int z1,int z2,int z3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 0;
    int y = 0;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y == 0) &&
(x == 0) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre)
    */
    
            while(y >= 0) {
        y = y + x;
    }
    

}