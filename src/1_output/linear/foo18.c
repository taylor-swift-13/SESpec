
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
    
    
    while (x < n) {
        
        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }
 
    

}