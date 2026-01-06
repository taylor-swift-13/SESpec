
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo293(int i, int j, int r) 

            /*@
            Require r > i + j
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((i@pre > 0) => (i + j == i@pre + j@pre)) &&
((i@pre > 0) => (r > i + j)) &&
((!(i@pre > 0)) => ((r == r@pre)&&(j == j@pre)&&(i == i@pre))) &&
(r == r@pre
      loop assigns i, j)
    */
    
    while (i > 0) {
       i = i - 1;
       j = j + 1;
    }

    

  }