
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo186() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x >= 0) &&
(y >= 0) &&
(z % 10 == 0) &&
(w % 10 == 0) &&
(3 * x >= y) &&
(z == w
          loop assigns x, y, z, w)
    */
    
            while(unknown()){
       if(x >= 4){
       x = x + 1;
       y = y + 3;
       z = z + 10;
       w = w + 10;
      }
       else if(x >= z && w > y){
       x = 0 - x;
       y = 0 - y;
      }
       else{
       x = x + 1;
       y = y + 2;
      }
      }

    

  }