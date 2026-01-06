
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo174(int x, int y) 

            /*@
            Require x >= 0 && y >= 0 && x == y
            Ensure Results(__return)
            */
            {

    int n;

    n = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (x == y) &&
((x@pre != 0) => (x >= n)) &&
((!(x@pre != 0)) => ((n == 0)&&(y == y@pre)&&(x == x@pre))) &&
(n == 0
          loop assigns x, y)
    */
    
            while(x != n){
       x = x - 1;
       y = y - 1;
      }

    

  }