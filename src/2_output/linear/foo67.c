
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo67(int n,int y) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    
    int x = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= n@pre) => (((x == 1)&&(y == y@pre)&&(n == n@pre)) || (y == n - x + 1))) &&
((1 <= n@pre) => (x <= n + 1)) &&
((!(1 <= n@pre)) => ((x == 1)&&(y == y@pre)&&(n == n@pre))) &&
(n == n@pre
          loop assigns x, y)
    */
    
            while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    


}