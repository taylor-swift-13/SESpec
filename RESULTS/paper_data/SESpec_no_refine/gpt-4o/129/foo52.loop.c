
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer max_prefix_sum(int* array, integer begin, integer end) =
    begin >= end ? 0 : \max(sum(array, begin, k) | begin <= k <= end);
*/

/*@
  logic integer max_subarray_sum(int* array, integer begin, integer end) =
    begin >= end ? 0 : \max(sum(array, i, j) | begin <= i <= j <= end);
*/

/*@
  logic integer max_subarray_start(int* array, integer begin, integer end) =
    begin >= end ? begin : \argmax(sum(array, i, j) | begin <= i <= j <= end, i);
*/

/*@
  logic integer max_subarray_end(int* array, integer begin, integer end) =
    begin >= end ? begin : \argmax(sum(array, i, j) | begin <= i <= j <= end, j);
*/

int foo52(int * a, int a_len, int Array) {

    int max_so_far = 0;
    int max_ending_here = 0;
    int max = 0;
    int stop = 0;
    int step = 0;

    /*@
      loop invariant 0 <= n <= Array;
      loop invariant max_ending_here == sum(a, step, n);
      loop invariant max_so_far == max_subarray_sum(a, 0, n);
      loop invariant max == max_subarray_start(a, 0, n);
      loop invariant stop == max_subarray_end(a, 0, n);
      loop invariant Array == \at(Array, Pre);
      loop invariant a_len == \at(a_len, Pre);
      loop invariant a == \at(a, Pre);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns n, max_ending_here, max_so_far, max, stop, step;
    */
    for (int n = 0; n < Array; n++) {
        max_ending_here += a[n];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            max = step;
            stop = n;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            step = n + 1;
        }
    }

    return stop - max + 1;
}
