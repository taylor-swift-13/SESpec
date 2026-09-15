#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo261(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int i = 0;
        int j = a_len - 1;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i) &&
    (j < a_len@pre) &&
    (a_len < 0 || i <= j + 1) &&
    ((0 <= a_len@pre - 1) => (((j == a_len@pre - 1)&&(i == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= i && i <= a_len@pre))) &&
    ((0 <= a_len@pre - 1) => (((j == a_len@pre - 1)&&(i == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (-1 <= j && j < a_len@pre))) &&
    ((!(0 <= a_len@pre - 1)) => ((j == a_len@pre - 1)&&(i == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre))) &&
    (x == x@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len@pre => a_l[k] == a_l[k]@pre)
    */
while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}