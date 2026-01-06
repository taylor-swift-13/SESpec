
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo187() 

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
    ((x >= 4) => (y > 2)) &&
(z == 10 * w) &&
(x == w) &&
((x < 4) => (y == 100 * x)) &&
((x >= 4) => (y >= 2*(x - 4) + 400 - 100*(w - 4))
      loop assigns x, y, z, w)
    */
    
    while(unknown()) {
       if(x >= 4) {
           x = x + 1;
           y = y + 2;
       }
       else if(y > 10 * w && z >= 100 * x) {
           y = 0 - y;
       }
       else {
           x = x + 1;
           y = y + 100;
       }
       w = w + 1;
       z = z + 10;
    }

    

  }