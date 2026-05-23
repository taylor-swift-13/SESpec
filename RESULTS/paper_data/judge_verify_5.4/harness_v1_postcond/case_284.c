#include <limits.h>



/*@requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr[0] >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures arr_len == 1 ==> \result >= 0;*/
int stub_A(int * arr, int arr_len);

/*@loop invariant result == 0 || min <= arr[i-1];
        loop invariant result == 0 || result >= min;
        loop invariant result == 0 || result >= 0;
        loop invariant result == 0 || min <= result;
        loop invariant result == 0 || min <= arr[0];
        loop invariant result == 0 ==> min <= arr[0];
        loop invariant result == 0 ==> i >= 1;
        loop invariant result == 0 ==> \forall integer k; 1 <= k < i ==> arr[k] >= min;
        loop invariant result == 0 ==> \forall integer k; 0 <= k < i ==> arr[k] >= min;
        loop invariant result == 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min);
        loop invariant result != 0 ==> result >= min;
        loop invariant min == arr[0] || i > 0;
        loop invariant min == arr[0] || (\exists integer k; 1 <= k < i && min == arr[k]);
        loop invariant min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k]);
        loop invariant min <= result || result == 0;
        loop invariant min <= arr[i-1];
        loop invariant min <= arr[i-1] || i == 1;
        loop invariant min <= arr[0];
        loop invariant min <= arr[0] || result == 0;
        loop invariant i == 1 ==> result == 0;
        loop invariant i == 1 ==> min == arr[0];
        loop invariant \forall integer k; 1 <= k < i ==> min <= arr[k];
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] >= min;
        loop invariant \forall integer k; 1 <= k < i ==> (arr[k] <= min || min <= arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> min == arr[k] || min < arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k] || arr[k] <= min;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= min;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] >= min || min >= arr[k]);
        loop invariant \exists integer k; 0 <= k < i && min == arr[k];
        loop invariant \exists integer k; 0 <= k < i && min == arr[k] || i == 1;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == min;
        loop invariant 1 <= i;
        loop invariant 0 <= result;
        loop invariant 0 <= result || 0 <= min;
        loop invariant 0 <= min || 0 <= result;
        loop invariant 0 <= min || 0 <= i;
        loop invariant 0 <= i;
        loop invariant 0 <= i || i <= arr_len;
        loop invariant 0 < i;
        loop assigns result;
        loop assigns min;
        loop assigns i;*/
int stub_B(int * arr, int arr_len);

/*@loop invariant result == 0 || min <= arr[i-1];
        loop invariant result == 0 || result >= min;
        loop invariant result == 0 || result >= 0;
        loop invariant result == 0 || min <= result;
        loop invariant result == 0 || min <= arr[0];
        loop invariant result == 0 ==> min <= arr[0];
        loop invariant result == 0 ==> i >= 1;
        loop invariant result == 0 ==> \forall integer k; 1 <= k < i ==> arr[k] >= min;
        loop invariant result == 0 ==> \forall integer k; 0 <= k < i ==> arr[k] >= min;
        loop invariant result == 0 ==> (\forall integer k; 0 <= k < i ==> arr[k] >= min);
        loop invariant result != 0 ==> result >= min;
        loop invariant min == arr[0] || i > 0;
        loop invariant min == arr[0] || (\exists integer k; 1 <= k < i && min == arr[k]);
        loop invariant min == arr[0] || (\exists integer k; 0 <= k < i && min == arr[k]);
        loop invariant min <= result || result == 0;
        loop invariant min <= arr[i-1];
        loop invariant min <= arr[i-1] || i == 1;
        loop invariant min <= arr[0];
        loop invariant min <= arr[0] || result == 0;
        loop invariant i == 1 ==> result == 0;
        loop invariant i == 1 ==> min == arr[0];
        loop invariant \forall integer k; 1 <= k < i ==> min <= arr[k];
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] >= min;
        loop invariant \forall integer k; 1 <= k < i ==> (arr[k] <= min || min <= arr[k]);
        loop invariant \forall integer k; 0 <= k < i ==> min == arr[k] || min < arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k] || arr[k] <= min;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= min;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] >= min || min >= arr[k]);
        loop invariant \exists integer k; 0 <= k < i && min == arr[k];
        loop invariant \exists integer k; 0 <= k < i && min == arr[k] || i == 1;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == min;
        loop invariant 1 <= i;
        loop invariant 0 <= result;
        loop invariant 0 <= result || 0 <= min;
        loop invariant 0 <= min || 0 <= result;
        loop invariant 0 <= min || 0 <= i;
        loop invariant 0 <= i;
        loop invariant 0 <= i || i <= arr_len;
        loop invariant 0 < i;
        loop assigns result;
        loop assigns min;
        loop assigns i;*/
int check_A_implies_B(int * arr, int arr_len) {
    return stub_A(arr, arr_len);
}

/*@requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr[0] >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures arr_len == 1 ==> \result >= 0;*/
int check_B_implies_A(int * arr, int arr_len) {
    return stub_B(arr, arr_len);
}
