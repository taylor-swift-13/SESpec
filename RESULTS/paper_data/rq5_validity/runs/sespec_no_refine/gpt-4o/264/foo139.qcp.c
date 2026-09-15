#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo139(int * seqNums, int seqNums_len);

const char * foo139(int * seqNums, int seqNums_len) 
/*@
With seqNums_l
Require store_int_array(seqNums, seqNums_len, seqNums_l) && seqNums_len > 0 && seqNums_len < 100
Ensure Results(__return)
*/{

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  seqNums_l,    
    store_int_array(seqNums, seqNums_len, seqNums_l) && seqNums_len > 0 && seqNums_len < 100 &&
    (forall (k:Z), 0 <= k && k < seqNums_len => seqNums_l[k] == seqNums_l[k]@pre
      loop assigns i)
    */
    
    for (int i = 1; i < seqNums_len; i++) {
        if (seqNums[i] - seqNums[i - 1] != difference) {
            return "Non Linear Sequence";
        }
    }
        return "Linear Sequence";
}