#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <string.h>

int foo126(const char * jewels, const char * stones);

int foo126(const char * jewels, const char * stones) 
/*@
With jewels_l stones_l
Require store_int_array(jewels, stones, jewels_l) && stones > 0 && stones < 100 && store_int_array(stones, 100, stones_l)
Ensure Results(__return)
*/{

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
           
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int j = 0; j < jewelsLength; j++) {
                char jewel = jewels[j];
                if (stone == jewel) {
                    jewelsCount++;
                    break;
                }
            }
        }
        return jewelsCount;
}