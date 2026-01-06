
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo194(int i) 

            /*@
            Require i >= 0
            Ensure Results(__return)
            */
            {

    int x;
    int y;
    int z;

    x = i;
    y = i;
    z = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((i@pre != 0) => (x == i@pre - z)) &&
((i@pre != 0) => (y == i@pre - 2*z)) &&
((i@pre != 0) => (z >= 0 && z <= i@pre)) &&
((!(i@pre != 0)) => ((z == 0)&&(y == i@pre)&&(x == i@pre)&&(i == i@pre))) &&
(i == i@pre
      loop assigns x, y, z)
    */
    
    while(x != 0) {
       x = x - 1;
       y = y - 2;
       z = z + 1;
    }

    

  }