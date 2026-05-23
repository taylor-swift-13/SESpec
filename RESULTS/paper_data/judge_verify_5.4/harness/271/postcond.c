#include <limits.h>

/*@ logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0); */
/*@ logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1)); */

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= arrSize <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result % 2 != 0; */
int stub_A(int * arr, int arr_len, int arrSize);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr, int arr_len, int arrSize);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr, int arr_len, int arrSize) {
    return stub_A(arr, arr_len, arrSize);
}

/*@ requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= arrSize <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result % 2 != 0; */
int check_B_implies_A(int * arr, int arr_len, int arrSize) {
    return stub_B(arr, arr_len, arrSize);
}
