
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo192(int i, int n) 

            /*@
            Require i < n
            Ensure Results(__return)
            */
            {

    int b;

    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i >= 0) &&
(n == n@pre
          loop assigns i)
    */
    
            while(i < n && b != 0){
       i = i + 1;
      }

    

  }