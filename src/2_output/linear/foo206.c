
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo206(int x, int z) 

            /*@
            Require x > -100 && x < 200 && z > 100 && z < 200
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(x@pre < 100 && z@pre > 100)) => 
            ((z == z@pre)&&(x == x@pre))
          loop assigns x, z)
    */
    
        while(x < 100 && z > 100){
            if(unknown()){
                x = x + 1;
            }
            else{
                x = x - 1;
                z = z - 1;
            }
        }

    

  }