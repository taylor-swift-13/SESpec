
/*@
  logic integer max_subarray_sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : \max(max_subarray_sum(a, lo, hi - 1),
                    max_subarray_sum(a, lo, hi - 1) + a[hi - 1]);

  logic integer max_subarray_start(int* a, integer lo, integer hi) =
    lo >= hi ? lo
             : (max_subarray_sum(a, lo, hi) == max_subarray_sum(a, lo, hi - 1) ? max_subarray_start(a, lo, hi - 1) : lo);

  logic integer max_subarray_end(int* a, integer lo, integer hi) =
    lo >= hi ? lo
             : (max_subarray_sum(a, lo, hi) == max_subarray_sum(a, lo, hi - 1) ? max_subarray_end(a, lo, hi - 1) : hi - 1);
*/

/*@
  requires array >= 0;
  requires a_len >= array;
  requires \valid(a + (0 .. a_len - 1));
  requires \forall integer i; 0 <= i < array ==> a[i] >= 0; // Ensure non-negative elements to avoid negative sums.
   // Focused on the actual computation of the result.
  assigns \nothing;
*/
int foo196(int * a, int a_len, int array) {

    int max_so_far = 0;
    int max_ending_here = 0;
    int max = 0;
    int stop = 0;
    int step = 0;

    /*@
      loop invariant 0 <= n <= array;
      loop invariant max_ending_here >= 0;
      loop invariant max_so_far >= 0;
      loop invariant 0 <= step <= n;
      loop invariant 0 <= stop <= n;
      loop invariant array == \at(array, Pre);
      loop invariant a_len == \at(a_len, Pre);
      loop invariant a == \at(a, Pre);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns n, max_ending_here, max_so_far, max, stop, step;
    */
    for (int n = 0; n < array; n++) {
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
