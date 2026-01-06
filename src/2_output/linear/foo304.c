
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo304() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    unsigned int x;
    unsigned int z;

    x = 0;
    z = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x <= 10000000) &&
(z == 2 * (x >= 5000000 ? x - 5000000 : 0)) &&
(z % 2 == 0
      loop assigns x, z)
    */
    
    while (x < 10000000) {
        if (x >= 5000000) {
            z = z + 2;
        }
        x++;
    }

    

  }