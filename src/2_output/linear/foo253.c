
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo253() 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 1;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i == 2*a + 1) &&
(j == a + 1) &&
(a >= 0) &&
(b == -(a * (a - 1)) / 2
      loop assigns a, b, i, j)
    */
    
    while (unknown()) {
        a = a + 1;
        b = b + j - i;
        i = i + 2;
        if (i % 2 == 0) {
            j = j + 2;
        }
        else {
            j = j + 1;
        }
    }

    

  }