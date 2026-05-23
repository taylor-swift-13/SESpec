
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0; // Ensure the array is non-empty
  requires n >= 0 && n <= arr_len; // Ensure the range [start, end] is valid
  requires \forall integer i; 0 <= i < arr_len - 1 ==> arr[i] <= arr[i + 1]; // Ensure the array is sorted
  assigns \nothing;
  ensures \result >= -1 && \result < arr_len; // Postcondition 1
  ensures \result != -1 ==> arr[\result] == \result;
*/
int foo263(int * arr, int arr_len, int n) {

    int start = 0;
    int end = n - 1;

    /*@
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant start >= 0 && end < arr_len; // Ensure the range [start, end] is valid
      loop invariant \exists integer k; start <= k <= end ==> arr[k] == k || start > end;
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns start, end;
      loop variant end - start;
    */
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] < mid) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}
