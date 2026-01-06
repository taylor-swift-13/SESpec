
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo21(int n,int z1,int z2,int z3) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {
    int x = 1;
    int m = 1;

    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 < n@pre) => (1 <= x && x <= n@pre)) &&
((1 < n@pre) => (((m == 1)&&(x == 1)&&(z3 == z3@pre)&&(z2 == z2@pre)&&(z1 == z1@pre)&&(n == n@pre)) || (1 <= m && m < x))) &&
((!(1 < n@pre)) => ((m == 1)&&(x == 1)&&(z3 == z3@pre)&&(z2 == z2@pre)&&(z1 == z1@pre)&&(n == n@pre))) &&
(z3 == z3@pre) &&
(z2 == z2@pre) &&
(z1 == z1@pre) &&
(n == n@pre
      loop assigns x, m)
    */
    
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    

}