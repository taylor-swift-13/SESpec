#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (jewelsCount >= 0) &&
    (forall (k:Z), 0 <= k && k < i => (exists (m:Z), 0 <= m && m < jewelsLength && stones_l[k] == jewels_l[m]))
    */
for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
           
  /*1*/ 
 /*@ Inv
    exists  jewels_l stones_l,    
    store_int_ptr(jewels) && store_int_ptr(stones) &&
    (0 <= j && j <= jewelsLength) &&
    (forall (k:Z), 0 <= k && k < j => stones_l[i] != jewels_l[k])
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