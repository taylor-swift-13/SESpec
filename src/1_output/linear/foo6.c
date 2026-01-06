
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo6(int v1, int v2 ,int v3,int size, int y, int z) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    
    int x = 0;

    while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }

    

}