
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo138(int v1, int v2, int v3) 

            /*@
            Require v3 >= 0 && v1 <= 5 && (v1 - v3) >= 0 && v2 * 2 - v1 - v3 == 0 && v2 + 5 >= 0 && v2 <= 5
            Ensure Results(__return)
            */
            {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((v2@pre + 5 >= 0 && v2@pre <= 5) => (x1 == 100 + t * v1)) &&
((v2@pre + 5 >= 0 && v2@pre <= 5) => (x3 == -50 + t * v3)) &&
((v2@pre + 5 >= 0 && v2@pre <= 5) => (t >= 0)) &&
((v2@pre + 5 >= 0 && v2@pre <= 5) => (x2 <= 75 + t * 5)) &&
((!(v2@pre + 5 >= 0 && v2@pre <= 5)) => 
            ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == v3@pre)&&(v2 == v2@pre)&&(v1 == v1@pre))) &&
(v3 == v3@pre) &&
(v1 == v1@pre
          loop assigns x1, x2, x3, v2, t)
    */
    
            while(v2 + 5 >= 0 && v2 <= 5){
       x1 = x1 + v1;
       x3 = x3 + v3;
       x2 = x2 + v2;
       if(x2 * 2 - x1 - x3 >= 0){
       v2 = v2 - 1;
       }
       else if(x2 * 2 - x1 - x3 <= 0){
       v2 = v2 + 1;
       }
       t = t + 1;
      }

    

  }