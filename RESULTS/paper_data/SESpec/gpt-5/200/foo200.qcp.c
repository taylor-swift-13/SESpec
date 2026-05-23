#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
int foo200(int * a, int a_len, int size) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (size == size@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] == a_l[k]@pre) &&
    (0 <= s && s <= i + 1) &&
    (max_ending_here >= 0) &&
    ((s == i + 1) => (max_ending_here == 0)) &&
    (max_so_far >= 0) &&
    (max_so_far >= max_ending_here) &&
    ((i < size@pre) => (((s == 0)&&(end == 0)&&(start == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(size == size@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (max_so_far >= 0 && max_so_far >= max_ending_here))) &&
    ((i < size@pre) => (((s == 0)&&(end == 0)&&(start == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(size == size@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= start && start <= i))) &&
    ((i < size@pre) => (((s == 0)&&(end == 0)&&(start == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(size == size@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= s && s <= i + 1))) &&
    (size == size@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
    */
for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return end - start + 1;
}