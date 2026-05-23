#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo126(const char * jewels, const char * stones) 
/*@
With jewels_l stones_l
Require store_int_array(jewels, stones, jewels_l) && stones > 0 && stones < 100 && store_int_array(stones, 100, stones_l)
Ensure Results(__return)
*/{

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
       
  /*0*/ 
 /*@ Inv
    exists  jewels_l stones_l,    
    store_int_array(jewels, stones, jewels_l) && stones > 0 && stones < 100 && store_int_array(stones, 100, stones_l) &&
    (0 <= i && i <= stonesLength) &&
    (jewelsCount >= 0)
    */
for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
           
  /*1*/ 
 /*@ Inv
    exists  jewels_l stones_l,    
    store_int_array(jewels, stones, jewels_l) && stones > 0 && stones < 100 && store_int_array(stones, 100, stones_l) &&
    (0 <= j && j <= jewelsLength) &&
    (jewelsCount >= 0)
    */
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