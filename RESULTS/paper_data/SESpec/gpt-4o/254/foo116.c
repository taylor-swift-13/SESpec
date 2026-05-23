
/*@
  predicate unchanged_array{L1,L2}(int* array, integer len) =
    \forall integer i; 0 <= i < len ==> \at(array[i], L1) == \at(array[i], L2);
*/

/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  requires \valid(array + (0 .. array_len - 1));
  requires start <= end; // Ensure valid range
  requires \forall integer i; 0 <= i < array_len ==> array[i] >= start && array[i] <= end; // Strengthened precondition
  ensures unchanged_array{Pre,Post}(array, array_len);
  assigns \nothing;
*/
int foo116(int * array, int array_len, int start, int end) {

    int min = start;
    int max = end;
    int mid;

    /*@
      loop invariant min >= \at(start,Pre) && max <= \at(end,Pre);
      loop invariant min <= max + 1;
      loop invariant min >= start; // Ensure min stays within bounds
      loop invariant max <= end;   // Ensure max stays within bounds
      loop invariant end == \at(end,Pre);
      loop invariant start == \at(start,Pre);
      loop invariant array_len == \at(array_len,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant unchanged_array{Pre,Here}(array, array_len);
      loop assigns mid, min, max;
      loop variant max - min;
    */
    while (min <= max) {
        mid = (min + max) / 2;
        int current = array[mid];

        if (current == mid) {
            min = mid + 1;
        } else if (current < mid) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return min;
}
