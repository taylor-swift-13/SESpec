
/*@
  logic integer array_eq_count(int* a, integer lo, integer hi, int v) =
    lo >= hi ? 0 : array_eq_count(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures \result >= \old(start);
  ensures \result >= 0;
  ensures \result >= \old(array_len) == 0 ? \old(start) : 0;
  ensures \result == \old(start) || \result > \old(end) || (\result >= \old(start) && \result <= \old(end));
*/
int foo116(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        
            
        /*@
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (min <= max));
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (min <= array_len - 1));
          loop invariant (!(\at(start,Pre) <= \at(end,Pre))) ==> ((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant end == \at(end,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k],Pre);
          loop assigns mid, current, min, max;
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
