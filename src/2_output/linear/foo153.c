
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo153() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int w;
    int z;

    w = 1;
    z = 0;
    x = 0;
    y = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == y) &&
((w == 0 && z == 1) || (w == 1 && z == 0 && x == 0 && y == 0)) &&
(((z == 0)&&(w == 1)&&(y == 0)&&(x == 0)) || (w == 0)) &&
(((z == 0)&&(w == 1)&&(y == 0)&&(x == 0)) || (z == 1))
    */
    
    while(unknown()) {
       if(w == 1 && z == 0){
       x = x + 1;
       w = 0;
       y = y + 1;
       z = 1;
      }
       else if(w != 1 && z == 0){
       y = y + 1;
       z = 1;
      }
       else if(w == 1 && z != 0){
       x = x + 1;
       w = 0;
      }
       else if(w != 1 && z != 0){
       continue;
      }
    }

    

  }