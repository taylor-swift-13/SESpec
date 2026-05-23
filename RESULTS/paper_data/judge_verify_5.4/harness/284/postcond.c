#include <limits.h>

/*@ requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr[0] >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures arr_len == 1 ==> \result >= 0; */
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

/*@ requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr[0] >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures arr_len == 1 ==> \result >= 0; */
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
