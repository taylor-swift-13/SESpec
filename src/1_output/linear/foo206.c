
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