#include <limits.h>



/*@requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;*/
int stub_A(int * arr, int arr_len);

/*@loop invariant sum == arr[0] || sum == arr[n-1] || sum <= arr[0];
		loop invariant sum == arr[0] || sum == arr[n-1] || \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant sum == arr[0] || sum == arr[n-1] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum == arr[0] || sum <= arr[0];
		loop invariant sum == arr[0] || \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant sum == arr[0] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum <= result;
		loop invariant sum <= arr[n-1];
		loop invariant sum <= arr[n-1] || n == 1;
		loop invariant sum <= arr[0];
		loop invariant sum <= arr[0] || n <= arr_len;
		loop invariant sum <= arr[0] || arr[0] <= result;
		loop invariant sum <= arr[0] || 0 <= result - sum;
		loop invariant result >= arr[n-1] || n == 1;
		loop invariant result == arr[0] || result >= arr[0];
		loop invariant result == arr[0] || result == arr[n-1] || result >= arr[n-1];
		loop invariant result == arr[0] || result == arr[n-1] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || result == arr[n-1] || (\exists integer k; 0 <= k < n && result == arr[k]);
		loop invariant result == arr[0] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || (\exists integer k; 0 <= k < n && result == arr[k]);
		loop invariant n == 1 || n > 1;
		loop invariant n <= arr_len || 0 <= result - sum;
		loop invariant arr[0] <= result;
		loop invariant arr[0] <= result || n <= arr_len;
		loop invariant arr[0] <= result || 0 <= result - sum;
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] && result >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] && arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> result >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> arr[0] <= result;
		loop invariant \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant 1 <= n;
		loop invariant 0 <= result - sum;
		loop invariant 0 <= n;
		loop invariant (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant (\exists integer k; 0 <= k < n && result == arr[k]);
		loop invariant (\exists integer k; 0 <= k < n && result == arr[k]) || n == 1;
		loop assigns sum;
		loop assigns result;
		loop assigns n;*/
int stub_B(int * arr, int arr_len);

/*@loop invariant sum == arr[0] || sum == arr[n-1] || sum <= arr[0];
		loop invariant sum == arr[0] || sum == arr[n-1] || \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant sum == arr[0] || sum == arr[n-1] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum == arr[0] || sum <= arr[0];
		loop invariant sum == arr[0] || \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant sum == arr[0] || (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant sum <= result;
		loop invariant sum <= arr[n-1];
		loop invariant sum <= arr[n-1] || n == 1;
		loop invariant sum <= arr[0];
		loop invariant sum <= arr[0] || n <= arr_len;
		loop invariant sum <= arr[0] || arr[0] <= result;
		loop invariant sum <= arr[0] || 0 <= result - sum;
		loop invariant result >= arr[n-1] || n == 1;
		loop invariant result == arr[0] || result >= arr[0];
		loop invariant result == arr[0] || result == arr[n-1] || result >= arr[n-1];
		loop invariant result == arr[0] || result == arr[n-1] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || result == arr[n-1] || (\exists integer k; 0 <= k < n && result == arr[k]);
		loop invariant result == arr[0] || \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant result == arr[0] || (\exists integer k; 0 <= k < n && result == arr[k]);
		loop invariant n == 1 || n > 1;
		loop invariant n <= arr_len || 0 <= result - sum;
		loop invariant arr[0] <= result;
		loop invariant arr[0] <= result || n <= arr_len;
		loop invariant arr[0] <= result || 0 <= result - sum;
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] && result >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> sum <= arr[k] && arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> result >= arr[k];
		loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= result;
		loop invariant \forall integer k; 0 <= k < n ==> arr[0] <= result;
		loop invariant \exists integer k; 0 <= k < n && sum == arr[k];
		loop invariant \exists integer k; 0 <= k < n && result == arr[k];
		loop invariant 1 <= n;
		loop invariant 0 <= result - sum;
		loop invariant 0 <= n;
		loop invariant (\exists integer k; 0 <= k < n && sum == arr[k]);
		loop invariant (\exists integer k; 0 <= k < n && result == arr[k]);
		loop invariant (\exists integer k; 0 <= k < n && result == arr[k]) || n == 1;
		loop assigns sum;
		loop assigns result;
		loop assigns n;*/
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@requires arr_len >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  assigns \nothing;*/
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
