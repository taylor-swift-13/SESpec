#include <limits.h>


/*@
  logic boolean strict_decreasing_prefix(int* a, integer lo, integer hi) =
    hi <= lo + 1 ? \true
                  : strict_decreasing_prefix(a, lo, hi - 1) && a[hi - 2] > a[hi - 1];
*/

/*@requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;*/
int stub_A(int * arr, int arr_len);

/*@loop invariant i == 0 || (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]);
        loop invariant i <= n + 1;
        loop invariant 1 <= n || n < 2;
        loop invariant 0 <= n;
        loop invariant n == arr_len;
        loop invariant n == arr_len && 2 <= n;
        loop invariant i > 0 ==> arr[i-1] > arr[i];
        loop invariant i == 0 || i > 0;
        loop invariant i == 0 || arr[i-1] >= arr[i];
        loop invariant i == 0 || arr[i-1] > arr[i];
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1];
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1];
        loop invariant i == 0 ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant i <= n;
        loop invariant i <= n && 0 <= i;
        loop invariant i < n ==> i + 1 <= n;
        loop invariant i < n ==> arr_len == n;
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1];
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1;
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1];
        loop invariant i < n + 1;
        loop invariant arr_len == n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1] || i == 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1];
        loop invariant 2 <= n;
        loop invariant 2 <= n || i == 0;
        loop invariant 2 <= n ==> i <= n;
        loop invariant 2 <= n ==> i < n + 1;
        loop invariant 2 <= n ==> 0 <= i;
        loop invariant 1 <= n;
        loop invariant 0 <= i;
        loop invariant 0 <= i ==> i <= n;
        loop invariant 0 <= i ==> i < n + 1;
        loop invariant 0 <= i && i <= n;
        loop assigns i;*/
int stub_B(int * arr, int arr_len);

/*@loop invariant i == 0 || (\forall integer k; 0 <= k < i ==> arr[k] > arr[k+1]);
        loop invariant i <= n + 1;
        loop invariant 1 <= n || n < 2;
        loop invariant 0 <= n;
        loop invariant n == arr_len;
        loop invariant n == arr_len && 2 <= n;
        loop invariant i > 0 ==> arr[i-1] > arr[i];
        loop invariant i == 0 || i > 0;
        loop invariant i == 0 || arr[i-1] >= arr[i];
        loop invariant i == 0 || arr[i-1] > arr[i];
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1];
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant i == 0 || \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1];
        loop invariant i == 0 ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant i <= n;
        loop invariant i <= n && 0 <= i;
        loop invariant i < n ==> i + 1 <= n;
        loop invariant i < n ==> arr_len == n;
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1];
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1;
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant i < n ==> \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1];
        loop invariant i < n + 1;
        loop invariant arr_len == n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= arr[k+1] + 1;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1] || i == 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != arr[k+1];
        loop invariant 2 <= n;
        loop invariant 2 <= n || i == 0;
        loop invariant 2 <= n ==> i <= n;
        loop invariant 2 <= n ==> i < n + 1;
        loop invariant 2 <= n ==> 0 <= i;
        loop invariant 1 <= n;
        loop invariant 0 <= i;
        loop invariant 0 <= i ==> i <= n;
        loop invariant 0 <= i ==> i < n + 1;
        loop invariant 0 <= i && i <= n;
        loop assigns i;*/
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;*/
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
