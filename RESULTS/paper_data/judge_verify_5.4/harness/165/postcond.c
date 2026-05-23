#include <limits.h>
#include <stddef.h>

/*@ requires arr_len >= 0;
  requires arr != \null ==> \valid(&arr[0] + (0..arr_len-1));
  requires arr != \null ==> \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null ==> \result >= 0; */
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

/*@ requires arr_len >= 0;
  requires arr != \null ==> \valid(&arr[0] + (0..arr_len-1));
  requires arr != \null ==> \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null ==> \result >= 0; */
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
