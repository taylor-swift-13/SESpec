#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */
/*@ logic integer count_min(int* a, integer lo, integer hi, integer m) =
    lo >= hi ? 0
             : count_min(a, lo, hi - 1, m) + (a[hi - 1] == m ? 1 : 0); */

/*@ requires \at(n,Pre) != 0 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  assigns \nothing;
  ensures n == \at(n,Pre);
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures \result == 0 || \result >= 1;
  ensures \at(n,Pre) == 0 ==> \result == 0; */
int stub_A(int n, int * arr, int arr_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int * arr, int arr_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int * arr, int arr_len) {
    return stub_A(n, arr, arr_len);
}

/*@ requires \at(n,Pre) != 0 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  assigns \nothing;
  ensures n == \at(n,Pre);
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures \result == 0 || \result >= 1;
  ensures \at(n,Pre) == 0 ==> \result == 0; */
int check_B_implies_A(int n, int * arr, int arr_len) {
    return stub_B(n, arr, arr_len);
}
