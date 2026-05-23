#include <limits.h>

/*@ logic integer sum_even_even(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_even(arr, lo, hi - 1)
               + ((hi - 1) % 2 == 0 && arr[hi - 1] % 2 == 0 ? arr[hi - 1] : 0); */

/*@ requires n >= 0;
  requires \valid_read(arr + (0..n-1));
  assigns \nothing;
  ensures \result == sum_even_even(arr, 0, n);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == sum_even_even(arr, 0, n - 1) + ((n - 1) % 2 == 0 && arr[n - 1] % 2 == 0 ? arr[n - 1] : 0);
  ensures \result >= sum_even_even(arr, 0, n); */
int stub_A(int * arr, int arr_len, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr, int arr_len, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr, int arr_len, int n) {
    return stub_A(arr, arr_len, n);
}

/*@ requires n >= 0;
  requires \valid_read(arr + (0..n-1));
  assigns \nothing;
  ensures \result == sum_even_even(arr, 0, n);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == sum_even_even(arr, 0, n - 1) + ((n - 1) % 2 == 0 && arr[n - 1] % 2 == 0 ? arr[n - 1] : 0);
  ensures \result >= sum_even_even(arr, 0, n); */
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
