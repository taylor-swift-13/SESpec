
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo277(int n) 

            /*@
            Require n >= 0 && n <= 20000001
            Ensure Results(__return)
            */
            {

    int i;
    int k;

    i = 0;
    k = n;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < n@pre) => (i == 2*(n@pre - k))) &&
((0 < n@pre) => (k == n@pre - i/2)) &&
((0 < n@pre) => (2*k >= n - 1)) &&
((!(0 < n@pre)) => ((k == n@pre)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre
          loop assigns i, k)
    */
    
            while (i < n) {
       k--;
       i += 2;
      }

    

  }