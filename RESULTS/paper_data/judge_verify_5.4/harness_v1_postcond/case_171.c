#include <limits.h>



/*@requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \old(c) <= 0 ==> \result == -1;
  ensures \old(c) > 0 ==> \true;
  ensures \result == (\old(c) <= 0 ? -1 : \result);*/
int stub_A(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

/*@loop invariant tmp < n ==> result < Array || tmp >= 0;
		loop invariant result < Array ==> tmp < n || result >= 0;
		loop invariant count - result == tmp || count - tmp == result;
		loop invariant tmp == count - result;
		loop invariant tmp <= count;
		loop invariant result >= tmp || tmp >= result;
		loop invariant result >= 0 && tmp >= 0;
		loop invariant result >= 0 && tmp >= 0 && count >= 0;
		loop invariant result == count - tmp;
		loop invariant result == count - tmp || tmp == count - result;
		loop invariant result == 0 || tmp == 0 || result + tmp >= 0;
		loop invariant result <= count;
		loop invariant result <= count && tmp <= count;
		loop invariant result + tmp == count;
		loop invariant result + tmp == count || result + tmp + 1 == count;
		loop invariant result + tmp <= count;
		loop invariant count == result + tmp;
		loop invariant count == result + tmp || count == result + tmp - 1;
		loop invariant count == result + tmp || count == result + tmp + 1;
		loop invariant count == 0 || result + tmp == count;
		loop invariant count - tmp == result;
		loop invariant count - result == tmp;
		loop invariant 0 <= tmp;
		loop invariant 0 <= result;
		loop invariant 0 <= result && 0 <= tmp;
		loop invariant 0 <= count;
		loop invariant (result < arr1_len && tmp < arr_len) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp]);
		loop invariant (result < arr1_len && tmp < arr_len) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (result < Array && tmp < n);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] >= arr[tmp] || arr1[result] <= arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] >= arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] != arr[tmp] || arr1[result] == arr[tmp]);
		loop assigns tmp;
		loop assigns result;
		loop assigns count;*/
int stub_B(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

/*@loop invariant tmp < n ==> result < Array || tmp >= 0;
		loop invariant result < Array ==> tmp < n || result >= 0;
		loop invariant count - result == tmp || count - tmp == result;
		loop invariant tmp == count - result;
		loop invariant tmp <= count;
		loop invariant result >= tmp || tmp >= result;
		loop invariant result >= 0 && tmp >= 0;
		loop invariant result >= 0 && tmp >= 0 && count >= 0;
		loop invariant result == count - tmp;
		loop invariant result == count - tmp || tmp == count - result;
		loop invariant result == 0 || tmp == 0 || result + tmp >= 0;
		loop invariant result <= count;
		loop invariant result <= count && tmp <= count;
		loop invariant result + tmp == count;
		loop invariant result + tmp == count || result + tmp + 1 == count;
		loop invariant result + tmp <= count;
		loop invariant count == result + tmp;
		loop invariant count == result + tmp || count == result + tmp - 1;
		loop invariant count == result + tmp || count == result + tmp + 1;
		loop invariant count == 0 || result + tmp == count;
		loop invariant count - tmp == result;
		loop invariant count - result == tmp;
		loop invariant 0 <= tmp;
		loop invariant 0 <= result;
		loop invariant 0 <= result && 0 <= tmp;
		loop invariant 0 <= count;
		loop invariant (result < arr1_len && tmp < arr_len) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp]);
		loop invariant (result < arr1_len && tmp < arr_len) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (result < Array && tmp < n);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] >= arr[tmp] || arr1[result] <= arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] == arr[tmp] || arr1[result] != arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] >= arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] <= arr[tmp] || arr1[result] > arr[tmp]);
		loop invariant (result < Array && tmp < n) ==> (arr1[result] != arr[tmp] || arr1[result] == arr[tmp]);
		loop assigns tmp;
		loop assigns result;
		loop assigns count;*/
int check_A_implies_B(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {
    return stub_A(arr1, arr1_len, arr, arr_len, Array, n, c);
}

/*@requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \old(c) <= 0 ==> \result == -1;
  ensures \old(c) > 0 ==> \true;
  ensures \result == (\old(c) <= 0 ? -1 : \result);*/
int check_B_implies_A(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {
    return stub_B(arr1, arr1_len, arr, arr_len, Array, n, c);
}
