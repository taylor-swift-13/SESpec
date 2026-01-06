
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void foo309(unsigned int n) 

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
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;


   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i + j + k + v4 + v3 == l) &&
(0 <= l && l <= n
      loop assigns i, j, k, v4, v3, l)
    */
    
    while (l < n) {
        if ((l % 5) == 0){
            v3 = v3 + 1;
        }
        else if ((l % 4) == 0) {
            v4 = v4 + 1;
        }
        else if((l % 3) == 0){
            i = i + 1;
        }
        else if((l % 2) == 0){
            j = j + 1;
        }
        else{
            k = k + 1;
        }
        l = l + 1;
    }

    

  }