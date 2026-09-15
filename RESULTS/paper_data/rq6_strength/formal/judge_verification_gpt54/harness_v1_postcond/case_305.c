#include <limits.h>



/*@requires n > 0;
  requires \valid_read(arr + (0 .. n - 1));
  assigns \nothing;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;*/
int stub_A(int * arr, int arr_len, int n);

/*@loop invariant \forall integer k; right <= k < n-1 ==> arr[k] <= arr[k+1] || arr[k] >= arr[k+1];
        loop invariant right == n - 1 || arr[right] >= arr[right + 1];
        loop invariant right <= n - 1;
        loop invariant right < n;
        loop invariant right + 1 <= n;
        loop invariant left == 0 || arr[left - 1] <= arr[left];
        loop invariant left == 0 || arr[left - 1] < arr[left];
        loop invariant left == 0 || arr[left - 1] < arr[left] || right == n - 1 || arr[right] >= arr[right + 1];
        loop invariant left == 0 || arr[left - 1] < arr[left] || arr[left - 1] <= arr[left];
        loop invariant \forall integer k; left <= k <= right ==> 0 <= k < n;
        loop invariant \forall integer k; 0 <= k < left ==> arr[k] <= arr[left] || arr[k] >= arr[left];
        loop invariant \exists integer p; left <= p;
        loop invariant 0 <= left;
        loop assigns right;
        loop assigns left;*/
int stub_B(int * arr, int arr_len, int n);

/*@loop invariant \forall integer k; right <= k < n-1 ==> arr[k] <= arr[k+1] || arr[k] >= arr[k+1];
        loop invariant right == n - 1 || arr[right] >= arr[right + 1];
        loop invariant right <= n - 1;
        loop invariant right < n;
        loop invariant right + 1 <= n;
        loop invariant left == 0 || arr[left - 1] <= arr[left];
        loop invariant left == 0 || arr[left - 1] < arr[left];
        loop invariant left == 0 || arr[left - 1] < arr[left] || right == n - 1 || arr[right] >= arr[right + 1];
        loop invariant left == 0 || arr[left - 1] < arr[left] || arr[left - 1] <= arr[left];
        loop invariant \forall integer k; left <= k <= right ==> 0 <= k < n;
        loop invariant \forall integer k; 0 <= k < left ==> arr[k] <= arr[left] || arr[k] >= arr[left];
        loop invariant \exists integer p; left <= p;
        loop invariant 0 <= left;
        loop assigns right;
        loop assigns left;*/
int check_A_implies_B(int * arr, int arr_len, int n) {
    return stub_A(arr, arr_len, n);
}

/*@requires n > 0;
  requires \valid_read(arr + (0 .. n - 1));
  assigns \nothing;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;*/
int check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
