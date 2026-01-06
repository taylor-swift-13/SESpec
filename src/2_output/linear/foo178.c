
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo178(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int x;

    x = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (0 <= x && x <= n)) &&
((!(0 < n@pre)) => ((x == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns x)
    */
    
            while(x < n){
       x = x + 1;
      }

    

  }