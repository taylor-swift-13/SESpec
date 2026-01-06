
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo314(unsigned int n) 

            /*@
            Require n <= 20000001
            Ensure Results(__return)
            */
            {

    unsigned
    unsigned int j;
    unsigned int i;
    unsigned int k;

    i = 0;
    k = 0;
    j = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i == j && j == k) &&
(i % 3 == 0) &&
(j % 3 == 0) &&
(k % 3 == 0) &&
((!(i < n)) => (i >= n && i == j && j == k)
      loop assigns i, j, k)
    */
    
    while (i < n) {
       i = i + 3;
       j = j + 3;
       k = k + 3;
    }

    

  }