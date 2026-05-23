#include <limits.h>

/*@ requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \old(c) <= 0 ==> \result == -1;
  ensures \old(c) > 0 ==> \true;
  ensures \result == (\old(c) <= 0 ? -1 : \result); */
int stub_A(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {
    return stub_A(arr1, arr1_len, arr, arr_len, Array, n, c);
}

/*@ requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \old(c) <= 0 ==> \result == -1;
  ensures \old(c) > 0 ==> \true;
  ensures \result == (\old(c) <= 0 ? -1 : \result); */
int check_B_implies_A(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {
    return stub_B(arr1, arr1_len, arr, arr_len, Array, n, c);
}
