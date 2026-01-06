
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo272() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i;
    int j;
    int k;

    i = 0;
    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= k) => (i == j)) &&
((0 <= k) => (i <= k + 1)) &&
((!(0 <= k)) => ((j == 0) && (i == 0))
      loop assigns i, j)
    */
    
    while (i <= k) {
       i++;
       j = j + 1;
    }

    

  }