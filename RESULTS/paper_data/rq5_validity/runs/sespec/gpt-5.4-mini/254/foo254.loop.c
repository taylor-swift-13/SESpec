
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo254(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /*@
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (start <= min);
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (max <= end);
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (min <= max + 1);
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (min <= \at(end,Pre) + 1);
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (\at(start,Pre) - 1 <= max);
          loop invariant (!(\at(start,Pre) <= \at(end,Pre))) ==> ((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant end == \at(end,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
          loop assigns mid, min, max;
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
