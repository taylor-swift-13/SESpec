
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo194(int i) 

            /*@
            Require i >= 0
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int z;

    x = i;
    y = i;
    z = 0;


    while(x != 0){
       x = x - 1;
       y = y - 2;
       z = z + 1;
      }

    

  }