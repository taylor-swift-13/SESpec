
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo183(int t, int x, int y) 

            /*@
            Require x != y && t == y
            Ensure Results(__return)
            */
            {

    int i;

    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre > 0) => (y >= t)) &&
((!(x@pre > 0)) => ((i == 0)&&(y == y@pre)&&(x == x@pre)&&(t == t@pre))) &&
(i == 0) &&
(x == x@pre) &&
(t == t@pre
          loop assigns y)
    */
    
            while(x > 0){
       y = x + y;
      }

    

  }