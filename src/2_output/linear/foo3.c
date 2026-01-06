
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo3(int y,int z) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((x == 0) && (z == z@pre) && (y == y@pre)) || 
                    (1 <= x && x <= 5 && (z <= y@pre => y == z) && (z > y@pre => y == y@pre))) &&
(0 <= x && x <= 5) &&
(z == z@pre
      loop assigns x, y)
    */
    
    while(x < 5) {
        x += 1;
        if(z <= y) {
            y = z;
        }
    }
   
   
}