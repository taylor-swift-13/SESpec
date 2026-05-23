
/*@
  logic integer prefix_max(int* a, integer hi) =
    hi <= 1 ? a[0]
            : (prefix_max(a, hi - 1) >= a[hi - 1] ? prefix_max(a, hi - 1) : a[hi - 1]);

  logic integer prefix_min(int* a, integer hi) =
    hi <= 1 ? a[0]
            : (prefix_min(a, hi - 1) <= a[hi - 1] ? prefix_min(a, hi - 1) : a[hi - 1]);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
  ensures arr_len == 1 ==> prefix_max(arr, arr_len) == prefix_min(arr, arr_len);
  ensures arr_len >= 1 ==> prefix_max(arr, arr_len) >= prefix_min(arr, arr_len);
  ensures arr_len >= 1 ==> \result >= 0;
*/
int foo234(int * arr, int arr_len) {

    int big = arr[0];
    int sum = arr[0];

    /*@
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant (n < arr_len) ==> (big >= sum);
      loop invariant (!(n < arr_len)) ==> (big >= sum);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns n, big, sum;
    */
    for (int n = 1; n < arr_len; n++) {
        if (arr[n] > big) {
            big = arr[n];
        }
        if (arr[n] < sum) {
            sum = arr[n];
        }
    }

    return big - sum;
}
