#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_odd_xor : Z -> Z -> Z) */
/*@ Extern Coq (cnt_suffix_from : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (cnt_odd_xor_pairs_up_to_i : Z -> Z -> Z -> Z) */
int foo238(int * a, int a_len, int n) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int count = 0;
        int length = a_len;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (length == a_len@pre) &&
    (n == n@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < a_len@pre => 0 <= a_l[k] && a_l[k] <= 100) &&
    (0 <= count) &&
    ((i < a_len@pre) => (0 <= i && i < length))
    */
for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i+1 <= j <= length;
          loop invariant 0 <= i < length;
          loop invariant 0 <= count;
          loop assigns j, count;
            */
            /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (i+1 <= j && j <= length) &&
    (0 <= i && i < length) &&
    (0 <= count)
    */
for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
        return count;
}