
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo171(int n) 

            /*@
            Require n > 0 && n < 10
            Ensure Results(__return)
            */
            {

    int i;
    int j;
    int k;
    int v;

    k = 0;
    i = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (i >= 0 && i <= n)) &&
((0 < n@pre) => (k >= 2000*i && k <= 4000*i)) &&
((!(0 < n@pre)) => ((k == 0)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
        loop assigns i, k, v)
    */
    
    while(i < n) {
        if(unknown()) {
            i = i + 1;
            k = k + 4000;
            v = 0;
        }
        else {
            i = i + 1;
            k = k + 2000;
            v = 1;
        }
    }

    

  }