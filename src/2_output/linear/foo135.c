
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo135() 

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


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (p + cl == c) &&
(0 <= p && p <= 4) &&
(cl > 0 => cl >= 0
      loop assigns p, cl)
    */
    
    while(p < 4 && cl > 0) {
       cl = cl - 1;
       p = p + 1;
    }

    

  }