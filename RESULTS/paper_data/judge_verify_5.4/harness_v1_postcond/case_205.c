#include <limits.h>



/*@requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures args_len <= 0 || arr_len <= 0 ==> \result == 0;
  ensures args_len > 0 && arr_len > 0 ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0;
  ensures \result == 0 ==> \true;*/
int stub_A(int * args, int args_len, int * arr, int arr_len, int Array);

/*@loop invariant ret < args_len && len < arr_len ==> ret + len >= 0;
		loop invariant ret >= 0 ==> ret + len >= len;
		loop invariant ret >= 0 && len >= 0;
		loop invariant ret == len ==> ret + len == 2 * ret;
		loop invariant ret == len ==> 0 <= ret;
		loop invariant ret == 0 || len == 0 || ret + len >= 0;
		loop invariant ret == 0 || len == 0 || ret + len > 0;
		loop invariant ret == 0 ==> len == 0 || ret + len >= 0;
		loop invariant ret <= ret + len;
		loop invariant ret <= ret + len || ret - len <= args_len;
		loop invariant ret <= ret + len || len <= ret + len;
		loop invariant ret <= ret + len && len <= ret + len;
		loop invariant ret <= len + args_len || ret <= ret + len;
		loop invariant ret <= args_len || ret <= ret + len;
		loop invariant ret <= args_len || len <= ret + len;
		loop invariant ret <= args_len ==> ret <= ret + len;
		loop invariant ret < args_len ==> len < arr_len || ret <= args_len;
		loop invariant ret < args_len ==> len < arr_len || ret < args_len;
		loop invariant ret < args_len ==> len < arr_len || ret + len >= 0;
		loop invariant ret < args_len && len < arr_len ==> ret + len < args_len + arr_len;
		loop invariant ret - len <= ret;
		loop invariant ret + len == 0 ==> ret == 0 && len == 0;
		loop invariant ret + len <= args_len + arr_len || ret <= ret + len;
		loop invariant ret + len <= args_len + arr_len || len <= ret + len;
		loop invariant len <= ret + len;
		loop invariant len <= ret + len || ret <= ret + len;
		loop invariant len <= ret + len || ret <= len + args_len;
		loop invariant len <= ret + len || ret - len <= args_len;
		loop invariant len <= ret + arr_len || ret <= ret + len;
		loop invariant len <= ret + arr_len || len <= ret + len;
		loop invariant len <= arr_len || ret <= ret + len;
		loop invariant len <= arr_len || len <= ret + len;
		loop invariant len <= arr_len ==> len <= ret + len;
		loop invariant len < arr_len ==> ret < args_len || len <= arr_len;
		loop invariant len < arr_len ==> ret < args_len || len < arr_len;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret + len;
		loop invariant 0 <= len;
		loop assigns ret;
		loop assigns len;*/
int stub_B(int * args, int args_len, int * arr, int arr_len, int Array);

/*@loop invariant ret < args_len && len < arr_len ==> ret + len >= 0;
		loop invariant ret >= 0 ==> ret + len >= len;
		loop invariant ret >= 0 && len >= 0;
		loop invariant ret == len ==> ret + len == 2 * ret;
		loop invariant ret == len ==> 0 <= ret;
		loop invariant ret == 0 || len == 0 || ret + len >= 0;
		loop invariant ret == 0 || len == 0 || ret + len > 0;
		loop invariant ret == 0 ==> len == 0 || ret + len >= 0;
		loop invariant ret <= ret + len;
		loop invariant ret <= ret + len || ret - len <= args_len;
		loop invariant ret <= ret + len || len <= ret + len;
		loop invariant ret <= ret + len && len <= ret + len;
		loop invariant ret <= len + args_len || ret <= ret + len;
		loop invariant ret <= args_len || ret <= ret + len;
		loop invariant ret <= args_len || len <= ret + len;
		loop invariant ret <= args_len ==> ret <= ret + len;
		loop invariant ret < args_len ==> len < arr_len || ret <= args_len;
		loop invariant ret < args_len ==> len < arr_len || ret < args_len;
		loop invariant ret < args_len ==> len < arr_len || ret + len >= 0;
		loop invariant ret < args_len && len < arr_len ==> ret + len < args_len + arr_len;
		loop invariant ret - len <= ret;
		loop invariant ret + len == 0 ==> ret == 0 && len == 0;
		loop invariant ret + len <= args_len + arr_len || ret <= ret + len;
		loop invariant ret + len <= args_len + arr_len || len <= ret + len;
		loop invariant len <= ret + len;
		loop invariant len <= ret + len || ret <= ret + len;
		loop invariant len <= ret + len || ret <= len + args_len;
		loop invariant len <= ret + len || ret - len <= args_len;
		loop invariant len <= ret + arr_len || ret <= ret + len;
		loop invariant len <= ret + arr_len || len <= ret + len;
		loop invariant len <= arr_len || ret <= ret + len;
		loop invariant len <= arr_len || len <= ret + len;
		loop invariant len <= arr_len ==> len <= ret + len;
		loop invariant len < arr_len ==> ret < args_len || len <= arr_len;
		loop invariant len < arr_len ==> ret < args_len || len < arr_len;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret + len;
		loop invariant 0 <= len;
		loop assigns ret;
		loop assigns len;*/
int check_A_implies_B(int * args, int args_len, int * arr, int arr_len, int Array) {
    return stub_A(args, args_len, arr, arr_len, Array);
}

/*@requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures args_len <= 0 || arr_len <= 0 ==> \result == 0;
  ensures args_len > 0 && arr_len > 0 ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result == 0 ==> \result >= 0;
  ensures \result == 0 ==> \true;*/
int check_B_implies_A(int * args, int args_len, int * arr, int arr_len, int Array) {
    return stub_B(args, args_len, arr, arr_len, Array);
}
