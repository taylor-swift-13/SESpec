#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (cstring_readable : Z -> Prop) */
/*@ Extern Coq (is_jewel_char : Z -> Z -> Z -> Prop) */
/*@ Extern Coq (count_matching_stones : Z -> Z -> Z -> Z -> Z) */

int foo126(const char * jewels, const char * stones) 
/*@
With jewels_l stones_l
Require store_int_ptr(jewels) && store_int_ptr(stones)
Ensure Results(__return)
*/{

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
       
  /*0*/ 
 /*@ Inv
    exists  jewels_l stones_l,    
    store_int_ptr(jewels) && store_int_ptr(stones) &&
    (0 <= i && i <= stonesLength) &&
    (0 <= jewelsCount && jewelsCount <= i) &&
    (jewelsCount == count_matching_stones(jewels, jewelsLength, stones, i))
    */
for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
           
  /*1*/ 
 /*@ Inv
    exists  jewels_l stones_l,    
    store_int_ptr(jewels) && store_int_ptr(stones) &&
    (0 <= j && j <= jewelsLength) &&
    (0 <= jewelsCount && jewelsCount <= i + 1)
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