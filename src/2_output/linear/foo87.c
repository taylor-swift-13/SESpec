
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


int foo87(int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int lock = 1;
    int x = y;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((y@pre != y@pre) => (y == y@pre + 1)) &&
((y@pre != y@pre) => (((x == y@pre)&&(lock == 1)&&(y == y@pre)) || (lock == 0))) &&
((y@pre != y@pre) => (((x == y@pre)&&(lock == 1)&&(y == y@pre)) || (x == y@pre))) &&
((!(y@pre != y@pre)) => ((x == y@pre)&&(lock == 1)&&(y == y@pre))
      loop assigns lock, x, y)
    */
    
    while (x != y) {
        if (unknown()) {
            lock = 1;
            x = y;
        } else {
            lock = 0;
            x = y;
            y = y + 1;
        }
    }
    
  }