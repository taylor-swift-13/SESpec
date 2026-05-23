
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires arr_len >= 0;
  assigns \nothing;
  ensures \result == 1 ==> \forall integer i; 0 <= i < arr_len - 1 ==> arr[i] > arr[i+1];
  ensures \result == 0 ==> \exists integer i; 0 <= i < arr_len - 1 && arr[i] <= arr[i+1];
*/
int foo42(int * arr, int arr_len) {

    int n = arr_len;
    if (n < 2) {
        return 1;
    }

    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
      loop invariant \forall integer k; i <= k < n ==> arr[k] == \at(arr[k], Pre);
      loop assigns i;
      loop variant n - i;
    */
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i+1])
            return 0;
    }

    return 1;
}
