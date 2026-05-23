
/*@
  predicate unchanged_array(int *a, integer len, int *a_pre) =
    \forall integer i; 0 <= i < len ==> a[i] == a_pre[i];
*/

/*@
  predicate left_prop(int *a, integer lo, integer hi) =
    \forall integer i; lo <= i < hi ==> a[i] <= i;
*/

/*@
  predicate right_prop(int *a, integer lo, integer hi) =
    \forall integer i; lo < i <= hi ==> a[i] >= i;
*/

/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
*/
int foo254(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (min >= \at(start,Pre) && max <= \at(end,Pre));
          loop invariant (!(\at(start,Pre) <= \at(end,Pre))) ==> ((max == \at(end,Pre)) && (min == \at(start,Pre)) && (end == \at(end,Pre)) && (start == \at(start,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre)));
          loop invariant end == \at(end,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant unchanged_array(array, array_len, \at(array,Pre));
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
