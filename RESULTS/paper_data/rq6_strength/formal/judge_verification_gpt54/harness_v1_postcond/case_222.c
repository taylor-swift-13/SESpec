#include <limits.h>


/*@
  logic integer odd_with_index(int* a, integer idx, integer lo, integer hi) =
    hi <= lo ? 0 :
    odd_with_index(a, idx, lo, hi - 1) +
      ((((a[idx] ^ a[hi - 1]) % 2) == 1) ? 1 : 0);

  logic integer paircount_prefix(int* a, integer i, integer n) =
    i <= 0 ? 0 :
    paircount_prefix(a, i - 1, n) +
      odd_with_index(a, i - 1, i, n);
*/

/*@requires 0 <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == paircount_prefix(arr, arr_len, arr_len);
  ensures \result >= 0;
  ensures \true;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
  ensures \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  ensures \true;*/
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

/*@requires 0 <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == paircount_prefix(arr, arr_len, arr_len);
  ensures \result >= 0;
  ensures \true;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
  ensures \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  ensures \true;*/
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
