
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];

  logic integer max_subarray_sum(int* array, integer begin, integer end) =
    begin >= end ? 0 : max_subarray_sum(array, begin, end - 1) > sum(array, begin, end) 
                  ? max_subarray_sum(array, begin, end - 1) : sum(array, begin, end);
*/

/*@
  requires \valid(a + (0..a_len-1)); // Array 'a' must be valid for its length
  requires a_len >= 0; // Array length must be non-negative
  requires array >= 0; // Parameter 'array' must be non-negative
  requires array == a_len; // 'array' must match the length of 'a'
  requires a_len == 0 || \exists integer i; 0 <= i < a_len; // If a_len > 0, array must contain at least one element
  requires \forall integer i; 0 <= i < a_len ==> a[i] >= 0; // All elements of 'a' must be non-negative
  assigns \nothing; // Function does not modify any caller-visible state
*/
int foo195(int *a, int a_len, int array) {
    int max_so_far = 0;
    int max_ending_here = 0;
    int max = 0;
    int stop = 0;
    int count = 0;

    /*@
      loop invariant 0 <= n <= array; // Ensures 'n' is within valid bounds
      loop invariant max_ending_here == sum(a, count, n); // Tracks the sum of the subarray starting at 'count' and ending at 'n'
      loop invariant \forall integer k; 0 <= k < n ==> max_subarray_sum(a, 0, k) == max_so_far || max_subarray_sum(a, 0, k) <= max_subarray_sum(a, 0, k + 1); // Tracks progression of max_subarray_sum
      loop invariant count >= 0 && count <= n; // Ensures 'count' is within valid bounds
      loop invariant stop >= 0 && stop <= n; // Ensures 'stop' is within valid bounds
      loop invariant array == \at(array, Pre); // Ensures 'array' remains unchanged
      loop invariant a_len == \at(a_len, Pre); // Ensures 'a_len' remains unchanged
      loop invariant a == \at(a, Pre); // Ensures 'a' remains unchanged
      loop assigns n, max_ending_here, max_so_far, max, stop, count; // Tracks variables modified in the loop
    */
    for (int n = 0; n < array; n++) {
        max_ending_here += a[n];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            max = count;
            stop = n;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            count = n + 1;
        }
    }

    return stop - max + 1;
}
