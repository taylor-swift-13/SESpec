#include <limits.h>

/*@ requires n >= 0;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < n && arr[\result] == \result);
  ensures \result == -1 ==> \result < 0;
  ensures \result != -1 ==> 0 <= \result < n;
  ensures \result != -1 ==> arr[\result] == \result; */
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
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < n && arr[\result] == \result);
  ensures \result == -1 ==> \result < 0;
  ensures \result != -1 ==> 0 <= \result < n;
  ensures \result != -1 ==> arr[\result] == \result; */
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
