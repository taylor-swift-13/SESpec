
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo106(int m,int j,int a) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (((k == 0)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre)) || (a <= m)) &&
(k == 0 || k == 1) &&
(a == a@pre) &&
(j == j@pre)
    */
    
    while (k < 1) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }

  

}