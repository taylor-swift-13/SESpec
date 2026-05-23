
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires start <= end;
  requires start >= 0;
  requires end < array_len;
  assigns \nothing;
  ensures \at(start, Pre) <= \at(end, Pre) ==> \at(start, Pre) <= \result <= \at(end, Pre) + 1;
  ensures \at(start, Pre) > \at(end, Pre) ==> \result == \at(start, Pre);
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
