#include <limits.h>

/*@ requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures args_len <= 0 || arr_len <= 0 ==> \result == 0;
  ensures args_len > 0 && arr_len > 0 ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0;
  ensures \result == 0 ==> \true; */
int stub_A(int * args, int args_len, int * arr, int arr_len, int Array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int * arr, int arr_len, int Array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int * arr, int arr_len, int Array) {
    return stub_A(args, args_len, arr, arr_len, Array);
}

/*@ requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures args_len <= 0 || arr_len <= 0 ==> \result == 0;
  ensures args_len > 0 && arr_len > 0 ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0;
  ensures \result == 0 ==> \true; */
int check_B_implies_A(int * args, int args_len, int * arr, int arr_len, int Array) {
    return stub_B(args, args_len, arr, arr_len, Array);
}
