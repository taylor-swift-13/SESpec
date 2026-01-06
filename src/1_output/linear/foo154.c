
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo154(int x) 

            /*@
            Require x > 0
            Ensure Results(__return)
            */
            {

    int i;
    int j;

    j = 0;
    i = 0;


    while(i < x){
       j = j + 2;
       i = i + 1;
      }

    

  }