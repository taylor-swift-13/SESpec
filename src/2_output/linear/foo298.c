
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo298() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int z;

    x = 0;
    z = 5000000;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= x && x <= 10000000) &&
(z == 5000000 - (x >= 5000000 ? x - 5000000 : 0)
      loop assigns x, z)
    */
    
    while(x < 10000000) {
       if(x >= 5000000)
       z--;
       x++;
    }

    

  }