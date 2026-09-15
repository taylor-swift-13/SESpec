```c
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
  logic integer sorted(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1 : (a[lo] <= a[lo + 1] && sorted(a, lo + 1, hi));
*/

/*@
  logic integer is_valid_index(int* a, integer len, integer idx) =
    0 <= idx < len;
*/

/*@
  logic integer binary_search_invariant(int* a, integer lo, integer hi, integer mid) =
    lo <= mid < hi;
*/


























































































































/*@
  logic integer binary_search_invariant(int* a, integer lo, integer hi, integer mid) =
    lo