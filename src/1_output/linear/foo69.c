
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo69(int n,int y,int v1,int v2,int v3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    
    int x = 1;

    
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    


}