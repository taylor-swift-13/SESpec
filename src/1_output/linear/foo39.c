
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo39(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int c = 0;

    while (unknown()){
        
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }
    }
           
    


}