
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo274() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i;
    int k;
    int n;

    i = 0;
    k = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n) => (i <= n && k == i)) &&
((0 < n) => (k <= n && i == k)) &&
((!(0 < n)) => ((k == 0) && (i == 0))
      loop assigns i, k)
    */
    
    while (i < n) {
        i = i + 1;
        k = k + 1;
    }

    

  }