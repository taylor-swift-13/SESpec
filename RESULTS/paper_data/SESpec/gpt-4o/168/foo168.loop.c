
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires arr_len >= 0;
  requires \valid(arr + (0 .. arr_len - 1));
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
*/
int foo168(int * arr, int arr_len) {

    int ret = 0;
    int count = arr_len - 1;

    /*@
      loop invariant 0 <= ret <= arr_len;
      loop invariant -1 <= count < arr_len;
      loop invariant ret <= count + 1;
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns ret, count;
    */
    while (ret <= count) {
        int r = ret + (count - ret) / 2;
        if (r < count && arr[r] > arr[r + 1]) {
            return r + 1;
        } else if (r > ret && arr[r] < arr[r - 1]) {
            return r;
        }
        if (arr[r] >= arr[ret]) {
            ret = r + 1;
        } else {
            count = r - 1;
        }
    }

    return 0;
}
