
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo279(int i, int j) 

            /*@
            Require i >= 1 && j >= 1 && i * i < j * j
            Ensure Results(__return)
            */
            {



   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((i@pre < j@pre) => (i >= 1 && j >= 1 && i <= j)) &&
((i@pre < j@pre) => (i + j <= i@pre + j@pre)) &&
((!(i@pre < j@pre)) => ((j == j@pre)&&(i == i@pre))
          loop assigns i, j)
    */
    
            while (i < j) {
       j = j - i;
       if (j < i) {
       j = j + i;
       i = j - i;
       j = j - i;
      }
      }

    

  }