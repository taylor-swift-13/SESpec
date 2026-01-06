
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo134() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int p;
    int c;
    int cl;

    p = 0;
    c = cl;


    while(((p < 4) && (cl > 0))){
       (cl = cl - 1);
       (p = p + 1);
      }

    

  }