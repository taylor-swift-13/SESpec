
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo91() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = 0;
    int y = 0;

    
    while(y >= 0) {
        y = y + x;
    }
    

}