
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo306(unsigned int n) 

            /*@
            Require n <= 20000001
            Ensure Results(__return)
            */
            {

    unsigned
    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;


    while (l < n) {
       if ((l % 2) == 0) {
       i = i + 1;
      }
       else{
       j = j + 1;
      }
       l = l + 1;
      }

    

  }