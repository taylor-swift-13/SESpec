#include <limits.h>

/*@ logic boolean strict_decreasing_prefix(int* a, integer lo, integer hi) =
    hi <= lo + 1 ? \true
                  : strict_decreasing_prefix(a, lo, hi - 1) && a[hi - 2] > a[hi - 1]; */

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing; */
int stub_A(int * arr, int arr_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr, int arr_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing; */
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
