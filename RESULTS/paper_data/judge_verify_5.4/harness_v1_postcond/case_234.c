#include <limits.h>


/*@ logic integer min_arr;(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] < min_arr;(arr, n-1) ? arr[n-1] : min_arr;(arr, n-1)); */

/*@ logic integer max_arr;(int *arr, integer n) =
      n == 1 ? arr[0] : (arr[n-1] > max_arr;(arr, n-1) ? arr[n-1] : max_arr;(arr, n-1)); */

/*@requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);*/
int stub_A(int * arr, int arr_len);

/*@loop invariant (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant (\exists integer k; 0 <= k < n && big == arr[k]);
		loop invariant sum == arr[0] || sum == arr[n-1] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum == arr[0] || sum <= arr[0];
		loop invariant sum == arr[0] || \exists integer k; 0 <= k <= n && sum == arr[k];
		loop invariant sum == arr[0] || \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant sum == arr[0] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum <= big;
		loop invariant sum <= arr[0];
		loop invariant big == arr[0] || big >= arr[0];
		loop invariant big == arr[0] || big == arr[n-1] || (\exists integer k; 0 <= k < n && big == arr[k]);
		loop invariant big == arr[0] || \exists integer k; 0 <= k <= n && big == arr[k];
		loop invariant big == arr[0] || \exists integer k; 0 <= k < n && big == arr[k];
		loop invariant big == arr[0] || (\exists integer k; 0 <= k < n && big == arr[k]);
		loop invariant arr[0] <= big;
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] <= big;
		loop invariant \forall integer k; 0 <= k < n ==> big >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= big;
		loop invariant \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant \exists integer k; 0 <= k < n && big == arr[k];
		loop invariant 1 <= n;
		loop invariant 0 <= n;
		loop invariant 0 <= n || n <= arr_len;
		loop invariant 0 <= n || 1 <= arr_len;
		loop invariant 0 < n;
		loop invariant (\exists integer k; 0 <= k < n && big == arr[k]) && (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop assigns sum;
		loop assigns n;
		loop assigns big;
		loop assigns arr[0..arr_len-1];*/
int stub_B(int * arr, int arr_len);

/*@loop invariant (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant (\exists integer k; 0 <= k < n && big == arr[k]);
		loop invariant sum == arr[0] || sum == arr[n-1] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum == arr[0] || sum <= arr[0];
		loop invariant sum == arr[0] || \exists integer k; 0 <= k <= n && sum == arr[k];
		loop invariant sum == arr[0] || \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant sum == arr[0] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum <= big;
		loop invariant sum <= arr[0];
		loop invariant big == arr[0] || big >= arr[0];
		loop invariant big == arr[0] || big == arr[n-1] || (\exists integer k; 0 <= k < n && big == arr[k]);
		loop invariant big == arr[0] || \exists integer k; 0 <= k <= n && big == arr[k];
		loop invariant big == arr[0] || \exists integer k; 0 <= k < n && big == arr[k];
		loop invariant big == arr[0] || (\exists integer k; 0 <= k < n && big == arr[k]);
		loop invariant arr[0] <= big;
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] <= big;
		loop invariant \forall integer k; 0 <= k < n ==> big >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= big;
		loop invariant \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant \exists integer k; 0 <= k < n && big == arr[k];
		loop invariant 1 <= n;
		loop invariant 0 <= n;
		loop invariant 0 <= n || n <= arr_len;
		loop invariant 0 <= n || 1 <= arr_len;
		loop invariant 0 < n;
		loop invariant (\exists integer k; 0 <= k < n && big == arr[k]) && (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop assigns sum;
		loop assigns n;
		loop assigns big;
		loop assigns arr[0..arr_len-1];*/
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);*/
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
