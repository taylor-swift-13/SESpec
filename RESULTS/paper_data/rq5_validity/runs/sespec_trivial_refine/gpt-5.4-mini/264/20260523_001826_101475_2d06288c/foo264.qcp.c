#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
const char * foo264(int * seqNums, int seqNums_len) 
/*@
With seqNums_l
Require store_int_array(seqNums, seqNums_len, seqNums_l)
Ensure Results(__return)
*/{

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

       
  /*0*/ 
 /*@ Inv
    exists  seqNums_l,    
    store_int_array(seqNums, seqNums_len, seqNums_l) &&
    (1 <= i && i <= seqNums_len) &&
    (forall (j:Z), 1 <= j && j < i => seqNums_l[j] - seqNums_l[j - 1] == difference)
    */
for (int i = 1; i < seqNums_len; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
        return "Linear Sequence";
}