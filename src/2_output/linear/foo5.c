
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo5(int size,int y,int z) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 0;
    
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < size@pre) => (((x == 0)&&(z == z@pre)&&(y == y@pre)&&(size == size@pre)) || (y == \min(y@pre, z)))) &&
((0 < size@pre) => (x >= 0 && x <= size@pre)) &&
((!(0 < size@pre)) => ((x == 0)&&(z == z@pre)&&(y == y@pre)&&(size == size@pre))) &&
(z == z@pre) &&
(size == size@pre
      loop assigns x, y)
    */
    
    while(x < size) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }

   
}