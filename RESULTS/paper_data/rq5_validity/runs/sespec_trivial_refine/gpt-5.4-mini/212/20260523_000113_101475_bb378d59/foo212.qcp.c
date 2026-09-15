#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n);

int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) 
/*@
With arr1_l arr2_l
Require store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr2, arr2_len, arr2_l)
Ensure (exists arr1_l_93 arr2_l_90 j_86, __return < arr1_len && j_86 >= arr2_len && __return < arr1_len && 0 <= __return && __return <= arr1_len && 0 <= j_86 && j_86 <= arr2_len && store_int_array(arr1, arr1_len, arr1_l_93) * store_int_array(arr2, arr2_len, arr2_l_90)) || (exists arr1_l_93 arr2_l_90 i_87, i_87 >= arr1_len && i_87 >= arr1_len && 0 <= i_87 && i_87 <= arr1_len && 0 <= __return && __return <= arr2_len && store_int_array(arr1, arr1_len, arr1_l_93) * store_int_array(arr2, arr2_len, arr2_l_90))
*/
{

        int i = 0;
        int j = 0;
       
  /*@ Inv
    exists  arr1_l arr2_l,    
    store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr2, arr2_len, arr2_l) &&
    (0 <= i && i <= arr1_len) &&
    (0 <= j && j <= arr2_len)
    */
while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1_len ? i : j;
}