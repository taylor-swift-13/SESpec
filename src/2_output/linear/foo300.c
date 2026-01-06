
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo300(int n) 

            /*@
            Require n <= 20000001
            Ensure Results(__return)
            */
            {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (i % 3 == 0 && i <= n + 2)) &&
((0 < n@pre) => (k % 3 == 0 && k <= i)) &&
((0 < n@pre) => (j % 3 == 0 && j <= i && i/2 <= j)) &&
((!(0 < n@pre)) => ((j == 0)&&(k == 0)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
        loop assigns i, j, k)
    */
    
    while (i < n) {
        i = i + 3;
        if ((i % 2) != 0)
            j = j + 3;
        else
            k = k + 3;
    }

    

  }