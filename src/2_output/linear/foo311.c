
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo311(unsigned int n) 

            /*@
            Require n <= 20000001
            Ensure Results(__return)
            */
            {

    unsigned
    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i && i <= n
    loop assigns i)
    */
    
  for (unsigned int i = 0; i < n; i++) {
    // Loop body
  }

    

  }