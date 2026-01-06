
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo33(int n,int v1,int v2,int v3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int x = n;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre > 0) => (x >= 0 && x <= n@pre)) &&
((!(n@pre > 0)) => ((x == n@pre)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(n == n@pre))) &&
(v3 == v3@pre) &&
(v2 == v2@pre) &&
(v1 == v1@pre) &&
(n == n@pre
      loop assigns x)
    */
    
    while (x > 0) {
        x = x - 1;
    }
  
   
  }