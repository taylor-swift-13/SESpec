#include <limits.h>


/*@
  predicate all_equal_prefix(int *arr, integer n, integer i, int v) =
    \forall integer k; 0 <= k < i ==> arr[k] == v;
*/

/*@requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == \null ==> \false;
  ensures \result == "NO" ==> n == 0 || n > 0;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);*/
const char * stub_A(int * arr, int arr_len, int n);

/*@loop invariant i == 0 || (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant n > 0 ==> i >= 1;
        loop invariant n > 0 ==> i == 1 || arr[i-1] == firstElement;
        loop invariant n > 0 ==> i == 1 || (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant n > 0 ==> i == 0 || i > 0;
        loop invariant n > 0 ==> i <= n;
        loop invariant n > 0 ==> i < n + 1;
        loop invariant n > 0 ==> firstElement == arr[0];
        loop invariant n > 0 ==> arr[i-1] == firstElement || i == 1;
        loop invariant n > 0 ==> arr[0] == firstElement;
        loop invariant n > 0 ==> \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
        loop invariant n > 0 ==> \forall integer k; 1 <= k < i ==> arr[k] == arr[0];
        loop invariant n > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant n > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant n > 0 ==> 1 <= i <= n;
        loop invariant n > 0 ==> (i == 1 || arr[i-1] == firstElement);
        loop invariant n > 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant i >= 1 ==> firstElement == arr[0];
        loop invariant i >= 1 ==> arr[i-1] == arr[0];
        loop invariant i >= 1 ==> \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant i > 0 ==> firstElement == arr[0];
        loop invariant i > 0 ==> arr[i-1] == firstElement;
        loop invariant i > 0 ==> arr[0] == firstElement;
        loop invariant i > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant i > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant i == 1 || i > 1;
        loop invariant i == 1 || arr[i-1] == firstElement;
        loop invariant i == 1 || arr[i-1] == arr[0];
        loop invariant i == 1 || \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
        loop invariant i == 1 || \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant i == 1 || (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant i == 1 || (\forall integer k; 0 <= k < i ==> arr[k] == arr[0]);
        loop invariant i == 0 || i >= 1;
        loop invariant i == 0 || i > 0;
        loop invariant i == 0 || arr[i-1] == firstElement;
        loop invariant firstElement == arr[0];
        loop invariant arr[0] == firstElement;
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] == arr[0];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement || k == 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement || arr[k] != firstElement;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement ==> arr[k] == arr[0];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != firstElement || arr[k] == firstElement;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == firstElement;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop invariant 0 < i;
        loop assigns i;*/
const char * stub_B(int * arr, int arr_len, int n);

/*@loop invariant i == 0 || (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant n > 0 ==> i >= 1;
        loop invariant n > 0 ==> i == 1 || arr[i-1] == firstElement;
        loop invariant n > 0 ==> i == 1 || (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant n > 0 ==> i == 0 || i > 0;
        loop invariant n > 0 ==> i <= n;
        loop invariant n > 0 ==> i < n + 1;
        loop invariant n > 0 ==> firstElement == arr[0];
        loop invariant n > 0 ==> arr[i-1] == firstElement || i == 1;
        loop invariant n > 0 ==> arr[0] == firstElement;
        loop invariant n > 0 ==> \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
        loop invariant n > 0 ==> \forall integer k; 1 <= k < i ==> arr[k] == arr[0];
        loop invariant n > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant n > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant n > 0 ==> 1 <= i <= n;
        loop invariant n > 0 ==> (i == 1 || arr[i-1] == firstElement);
        loop invariant n > 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant i >= 1 ==> firstElement == arr[0];
        loop invariant i >= 1 ==> arr[i-1] == arr[0];
        loop invariant i >= 1 ==> \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant i > 0 ==> firstElement == arr[0];
        loop invariant i > 0 ==> arr[i-1] == firstElement;
        loop invariant i > 0 ==> arr[0] == firstElement;
        loop invariant i > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant i > 0 ==> \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant i == 1 || i > 1;
        loop invariant i == 1 || arr[i-1] == firstElement;
        loop invariant i == 1 || arr[i-1] == arr[0];
        loop invariant i == 1 || \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
        loop invariant i == 1 || \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant i == 1 || (\forall integer k; 0 <= k < i ==> arr[k] == firstElement);
        loop invariant i == 1 || (\forall integer k; 0 <= k < i ==> arr[k] == arr[0]);
        loop invariant i == 0 || i >= 1;
        loop invariant i == 0 || i > 0;
        loop invariant i == 0 || arr[i-1] == firstElement;
        loop invariant firstElement == arr[0];
        loop invariant arr[0] == firstElement;
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] == arr[0];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement || k == 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement || arr[k] != firstElement;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement ==> arr[k] == arr[0];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == arr[0];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != firstElement || arr[k] == firstElement;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == firstElement;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop invariant 0 < i;
        loop assigns i;*/
const char * check_A_implies_B(int * arr, int arr_len, int n) {
    return stub_A(arr, arr_len, n);
}

/*@requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= n <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == \null ==> \false;
  ensures \result == "NO" ==> n == 0 || n > 0;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);*/
const char * check_B_implies_A(int * arr, int arr_len, int n) {
    return stub_B(arr, arr_len, n);
}
