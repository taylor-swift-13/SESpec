#include <limits.h>


/*@ 
  predicate TRUE = \true;
*/

/*@requires arr_len == 1;
  requires \valid(&arr[0]);
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \exists integer imax, imin;
            0 <= imax < arr_len &&
            0 <= imin < arr_len;
  ensures \result >= 0;
  ensures \result <= 100 || \result > 100;
  ensures \result == 0 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] == arr[0]);*/
int stub_A(int * arr, int arr_len);

/*@loop invariant result >= arr[0] && num <= arr[0];
		loop invariant result == arr[0] || result >= num;
		loop invariant result == arr[0] || result >= arr[0];
		loop invariant result == arr[0] || result == num || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || result == arr[n-1] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || num == arr[0] || result >= num;
		loop invariant result == arr[0] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant num == arr[0] || num == arr[n-1] || \exists integer k; 0 <= k < n && num == arr[k];
		loop invariant num == arr[0] || num <= result;
		loop invariant num == arr[0] || num <= arr[0];
		loop invariant num == arr[0] || \exists integer k; 0 <= k < n && num == arr[k];
		loop invariant num <= result;
		loop invariant num <= arr[0];
		loop invariant num <= arr[0] || num <= result;
		loop invariant n <= arr_len || num <= arr[0];
		loop invariant arr[0] <= result;
		loop invariant arr[0] <= result || result == arr[0];
		loop invariant arr[0] <= result || result <= arr[0];
		loop invariant arr[0] <= result || num <= arr[0];
		loop invariant arr[0] <= result || n <= arr_len;
		loop invariant arr[0] <= result || 0 <= result - num;
		loop invariant \forall integer k; 0 <= k < n ==> result >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> result >= arr[k] && num <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> num <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> num <= arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> num <= arr[k] && arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= result;
		loop invariant \exists integer k; 0 <= k < n && result >= arr[k];
		loop invariant \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant \exists integer k; 0 <= k < n && num == arr[k];
		loop invariant 1 <= n;
		loop invariant 0 <= result - num;
		loop invariant 0 <= result - num || num <= arr[0];
		loop invariant 0 <= result - num || n <= arr_len;
		loop invariant 0 <= n;
		loop invariant 0 < n;
		loop assigns result;
		loop assigns num;
		loop assigns n;*/
int stub_B(int * arr, int arr_len);

/*@loop invariant result >= arr[0] && num <= arr[0];
		loop invariant result == arr[0] || result >= num;
		loop invariant result == arr[0] || result >= arr[0];
		loop invariant result == arr[0] || result == num || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || result == arr[n-1] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || num == arr[0] || result >= num;
		loop invariant result == arr[0] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant num == arr[0] || num == arr[n-1] || \exists integer k; 0 <= k < n && num == arr[k];
		loop invariant num == arr[0] || num <= result;
		loop invariant num == arr[0] || num <= arr[0];
		loop invariant num == arr[0] || \exists integer k; 0 <= k < n && num == arr[k];
		loop invariant num <= result;
		loop invariant num <= arr[0];
		loop invariant num <= arr[0] || num <= result;
		loop invariant n <= arr_len || num <= arr[0];
		loop invariant arr[0] <= result;
		loop invariant arr[0] <= result || result == arr[0];
		loop invariant arr[0] <= result || result <= arr[0];
		loop invariant arr[0] <= result || num <= arr[0];
		loop invariant arr[0] <= result || n <= arr_len;
		loop invariant arr[0] <= result || 0 <= result - num;
		loop invariant \forall integer k; 0 <= k < n ==> result >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> result >= arr[k] && num <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> num <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> num <= arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> num <= arr[k] && arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= result;
		loop invariant \exists integer k; 0 <= k < n && result >= arr[k];
		loop invariant \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant \exists integer k; 0 <= k < n && num == arr[k];
		loop invariant 1 <= n;
		loop invariant 0 <= result - num;
		loop invariant 0 <= result - num || num <= arr[0];
		loop invariant 0 <= result - num || n <= arr_len;
		loop invariant 0 <= n;
		loop invariant 0 < n;
		loop assigns result;
		loop assigns num;
		loop assigns n;*/
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@requires arr_len == 1;
  requires \valid(&arr[0]);
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \exists integer imax, imin;
            0 <= imax < arr_len &&
            0 <= imin < arr_len;
  ensures \result >= 0;
  ensures \result <= 100 || \result > 100;
  ensures \result == 0 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] == arr[0]);*/
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
