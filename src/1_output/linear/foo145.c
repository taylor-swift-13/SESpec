
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo145(int mid) 

            /*@
            Require mid > 0
            Ensure Results(__return)
            */
            {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;


    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
      }

    

  }