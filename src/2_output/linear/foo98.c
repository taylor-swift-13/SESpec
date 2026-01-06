
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo98(int x) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int i =0;
    int j =0;
    int y =2;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= x@pre) => (i <= x + 1 && j == 2 * i)) &&
((0 <= x@pre) => (j == 2 * i)) &&
((!(0 <= x@pre)) => ((y == 2)&&(j == 0)&&(i == 0)&&(x == x@pre))) &&
(y == 2) &&
(x == x@pre
      loop assigns i, j)
    */
    
    while (i <= x) {
      i = i + 1;
      j = j + y;
    }
  
  
  
  }