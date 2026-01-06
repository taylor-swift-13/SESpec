
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
    
    
    while(x < 5) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }
   
   
}