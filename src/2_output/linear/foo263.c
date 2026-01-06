
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo263(int k) 

            /*@
            Require k >= 0 && k <= 20000001
            Ensure Results(__return)
            */
            {

    int n;
    int i;

    n = 0;
    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < 2 * k@pre) => (n == (i+1)/2 && i <= 2 * k@pre)) &&
((0 < 2 * k@pre) => (i >= 0 && n >= 0)) &&
((!(0 < 2 * k@pre)) => ((i == 0)&&(n == 0)&&(k == k@pre))) &&
(k == k@pre
        loop assigns n, i)
    */
    
    while (i < 2 * k) {
        if(i % 2 == 0) {
            n = n + 1;
        }
        i = i + 1;
    }

    

  }