
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo240(int x) 

            /*@
            Require x > -1 && x < 1
            Ensure Results(__return)
            */
            {

    unsigned int count;

    exp = 1;
    term = 1;
    count = 1;
    result = 2 * (1 / (1 - x));


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(unknown()){
       term = term * (x / count) ;
       exp = exp + term ;
       count++ ;
      }

    

  }