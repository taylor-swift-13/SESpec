
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo282(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int i;
    int k;

    i = 0;
    k = n;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre && n@pre > 0) => (i >= 0 && i <= n@pre) ) &&
((0 < n@pre && n@pre > 0) => (k == n@pre - i) ) &&
((!(0 < n@pre && n@pre > 0)) => ((k == n@pre)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns k, i)
    */
    
            while (i < n && n > 0) {
       k--;
       i++;
      }

    

  }