
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo265(int l) 

            /*@
            Require l > 0
            Ensure Results(__return)
            */
            {

    int n;
    int i;

    i = l;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((l@pre < n) => (i >= l@pre && i <= n && l == l@pre)) &&
((!(l@pre < n)) => ((i == l@pre) && (l == l@pre))) &&
(l == l@pre
        loop assigns i)
    */
    
    while (i < n) {
        i = i + 1;
    }

    

  }