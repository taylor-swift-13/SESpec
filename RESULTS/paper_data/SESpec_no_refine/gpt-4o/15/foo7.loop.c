
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer unchanged_array{L1, L2}(int* a, integer lo, integer hi) =
    \forall integer i; lo <= i < hi ==> \at(a[i], L1) == \at(a[i], L2);
*/

int foo7(int * arr, int arr_len, int key) {

    if (arr_len == 0) {
        return -1;
    } else {
        int low = 0;
        int high = arr_len;
        int mid = high / 2;

        /*@
          loop invariant 0 <= low <= high <= arr_len;
          loop invariant 0 <= mid < arr_len ==> arr[mid] != key;
          loop invariant \forall integer i; 0 <= i < low ==> arr[i] < key;
          loop invariant \forall integer i; high <= i < arr_len ==> arr[i] > key;
          loop invariant key == \at(key,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, 0, arr_len);
          loop assigns low, high, mid;
        */
        while (low < high && arr[mid] != key) {
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
            mid = low + (high - low) / 2;
        }

        if (low >= high) {
            return -1;
        }
        return mid;
    }
}
