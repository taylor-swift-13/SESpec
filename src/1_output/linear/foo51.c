
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo51(int n) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int c = 0;

    while (unknown()) {
        {
          if (unknown()) {
            if ( c != 4 )
            {
            c  = c + 1;
            }
          } else {
            if (c == 4) 
            {
            c  = 1;
            }
          }
    
        }
    
    } 
          
    
  

}