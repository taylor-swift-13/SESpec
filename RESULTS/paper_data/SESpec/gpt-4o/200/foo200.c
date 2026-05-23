
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer max_subarray_sum(int* array, integer begin, integer end) =
    begin >= end ? 0 : 
    max_subarray_sum(array, begin, end - 1) > sum(array, begin, end) ? 
    max_subarray_sum(array, begin, end - 1) : sum(array, begin, end);
*/

/*@
  logic integer max_subarray_start(int* array, integer begin, integer end) =
    begin >= end ? begin : 
    max_subarray_sum(array, begin, end - 1) > sum(array, begin, end) ? 
    max_subarray_start(array, begin, end - 1) : begin;
*/

/*@
  logic integer max_subarray_end(int* array, integer begin, integer end) =
    begin >= end ? begin : 
    max_subarray_sum(array, begin, end - 1) > sum(array, begin, end) ? 
    max_subarray_end(array, begin, end - 1) : end - 1;
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
*/
int foo200(int *a, int a_len, int size) {
    int max_so_far = 0;
    int max_ending_here = 0;
    int start = 0;
    int end = 0;
    int s = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < size;
      loop invariant max_so_far >= 0;
      loop invariant max_ending_here >= 0 || max_ending_here == sum(a, s, i);
      loop invariant size == \at(size, Pre);
      loop invariant a_len == \at(a_len, Pre);
      loop invariant a == \at(a, Pre);
      loop invariant start >= 0 && start <= i;
      loop invariant end >= 0 && end <= i;
      loop invariant s >= 0 && s <= i;
      loop assigns i, max_ending_here, max_so_far, start, end, s;
      loop variant size - i;
    */
    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    return end - start + 1;
}
