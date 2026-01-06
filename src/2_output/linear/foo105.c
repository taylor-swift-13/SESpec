
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo105(int n,int v1,int v2,int v3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
  
    int x = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (0 <= x && x <= n@pre)) &&
((!(0 < n@pre)) => ((x == 0)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(n == n@pre))) &&
(v3 == v3@pre) &&
(v2 == v2@pre) &&
(v1 == v1@pre) &&
(n == n@pre
      loop assigns x)
    */
    
    while (x < n) {
      x = x + 1;
    }
    
    
  }