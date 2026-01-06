
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo278(int i, int j, int k) 

            /*@
            Require k > i - j && i < j
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((i@pre < j@pre) => (i == i@pre + (k - k@pre))) &&
((i@pre < j@pre) => (k == k@pre + (i - i@pre))) &&
((!(i@pre < j@pre)) => ((k == k@pre)&&(j == j@pre)&&(i == i@pre))) &&
(j == j@pre
          loop assigns k, i)
    */
    
        while (i < j) {
            k = k + 1;
            i = i + 1;
        }

    

  }