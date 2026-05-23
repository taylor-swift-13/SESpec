#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_with : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (odd_pairs : Z -> Z -> Z -> Z) */
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
    (0 <= i) &&
    (count >= 0) &&
    (length == a_len@pre) &&
    (n == n@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
    */
for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i;
              loop invariant i <= length;
              loop invariant i + 1 <= j <= length;
              loop invariant 0 <= count;
              loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
              loop assigns j, count;
            */
            /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i) &&
    (i <= length) &&
    (i + 1 <= j && j <= length) &&
    (0 <= count) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
    */
for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
        return count;
}