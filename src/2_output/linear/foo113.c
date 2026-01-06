
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo113(int n,int v1,int v2,int v3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i = 1;
    int sn = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= n@pre) => (sn == i - 1)) &&
((1 <= n@pre) => (i <= n@pre + 1)) &&
((!(1 <= n@pre)) => ((sn == 0)&&(i == 1)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre)&&(n == n@pre))) &&
(v3 == v3@pre) &&
(v2 == v2@pre) &&
(v1 == v1@pre) &&
(n == n@pre
        loop assigns i, sn)
    */
    
    while (i <= n) {
        i = (i + 1);
        sn = (sn + 1);
    }
    
    
  
  }