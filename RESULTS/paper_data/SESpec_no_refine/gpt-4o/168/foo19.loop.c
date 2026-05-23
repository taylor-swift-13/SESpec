
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  predicate unchanged_array{L1,L2}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(a[i],L2);
*/

int foo19(int * arr, int arr_len) {

    int ret = 0;
    int count = arr_len - 1;

    /*@
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant unchanged_array{Pre,Here}(arr, arr_len);
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
