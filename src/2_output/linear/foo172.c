
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo172(int n) 

            /*@
            Require n > 0
            Ensure Results(__return)
            */
            {

    int i;
    int sum;

    sum = 0;
    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (0 <= i && i <= n@pre)) &&
((0 < n@pre) => (sum == (i * (i - 1)) / 2)) &&
((!(0 < n@pre)) => ((sum == 0)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
        loop assigns sum, i)
    */
    
    while(i < n) {
       sum = sum + i;
       i = i + 1;
    }

    

  }