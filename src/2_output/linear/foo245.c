
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


void foo245(int c, int last, int st) 

            /*@
            Require (st == 0 && last < c) || (st == 1 && last >= c)
            Ensure Results(__return)
            */
            {

    int a;
    int b;

    a = 0;
    b = 0;
    c = 200000;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((st != 0 || c != last + 1) => (a % 2 == 0 && b % 2 == 0)) &&
(st == st@pre) &&
(last == last@pre
        loop assigns a, b, c)
    */
    
    while(unknown()) {
        if(st == 0 && c == last + 1) {
            a = a + 3;
            b = b + 3;
        }
        else {
            a = a + 2;
            b = b + 2;
        }
        if(c == last && st == 0) {
            a = a + 1;
            c = c + 1;
        }
    }

    

  }