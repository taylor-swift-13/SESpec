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

       
  /*@ Inv
    exists  seqNums_l,    
    store_int_array(seqNums, seqNums_len, seqNums_l) &&
    (0 <= i) &&
    (difference == seqNums_l[1] - seqNums_l[0]) &&
    (forall (k:Z), 1 <= k && k < i => seqNums_l[k] - seqNums_l[k - 1] == difference) &&
    (forall (k:Z), 0 <= k && k < seqNums_len => seqNums_l[k] == seqNums_l[k]@pre) &&
    ((i <= seqNums_len) => (forall (k:Z), 1 <= k && k < i => seqNums_l[k] - seqNums_l[k - 1] == difference)) &&
    ((i == 1) || (exists (k:Z), 1 <= k && k < i && seqNums_l[k] - seqNums_l[k - 1] == difference)) &&
    ((!(i < seqNums_len)) => (forall (k:Z), 1 <= k && k < seqNums_len => seqNums_l[k] - seqNums_l[k - 1] == difference))
    */
for (int i = 1; i < seqNums_len; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
        return "Linear Sequence";
}