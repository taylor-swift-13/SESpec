
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo212() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int invalid;
    int unowned;
    int nonexclusive;
    int exclusive;
    int RETURN;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (\true
      loop assigns invalid, unowned, nonexclusive, exclusive)
    */
    
    while(!((nonexclusive + unowned) >= 1 && invalid >= 1)) {
        if(invalid >= 1) {
            if(unknown()) {
                nonexclusive = nonexclusive + exclusive;
                exclusive = 0;
                invalid = invalid - 1;
                unowned = unowned + 1;
            }
            else {
                exclusive = 1;
                unowned = 0;
                nonexclusive = 0;
            }
        }
        else if((nonexclusive + unowned) >= 1) {
            invalid = invalid + unowned + nonexclusive - 1;
            nonexclusive = 0;
            exclusive = exclusive + 1;
            unowned = 0;
        }
    }

  }