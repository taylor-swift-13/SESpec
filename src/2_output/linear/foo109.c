
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo109(int m,int j,int a,int c) 

            /*@
            Require emp
            Ensure Results(__return)
            */
            {

    int k = 0;
    
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < c@pre) => (((k == 0)&&(c == c@pre)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre)) || (a <= m))) &&
((0 < c@pre) => (k <= c)) &&
((!(0 < c@pre)) => ((k == 0)&&(c == c@pre)&&(a == a@pre)&&(j == j@pre)&&(m == m@pre))) &&
(c == c@pre) &&
(a == a@pre) &&
(j == j@pre
      loop assigns m, k)
    */
    
    while (k < c) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }

  
}