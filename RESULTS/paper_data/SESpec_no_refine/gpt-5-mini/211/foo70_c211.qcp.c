#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo70_c211(int * arr, int arr_len, int n);

int foo70_c211(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int count = 0;
        int i = 0;
        int j = 1;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((0 < n@pre && 1 < n@pre) => (1 <= j && j <= n)) &&
((!(0 < n@pre && 1 < n@pre)) => ((j == 1)&&(i == 0)&&(count == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(\valid(arr + (0 .. arr_len-1))
          loop assigns i, j, count)
    */
    
            while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}