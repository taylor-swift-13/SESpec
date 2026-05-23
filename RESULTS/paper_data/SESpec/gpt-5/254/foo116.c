
/*@ 
  predicate same_array{L1,L2}(int* a, integer n) =
    \forall integer k; 0 <= k < n ==> \at(a[k], L1) == \at(a[k], L2);
*/

/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
  assigns \nothing;
  ensures array == \old(array) && array_len == \old(array_len) && start == \old(start) && end == \old(end);
  ensures same_array{Pre,Here}(array, \old(array_len));
  ensures (start > end) ==> (\result == start);
  ensures (start <= end) ==> (start <= \result <= end + 1);
  ensures \result == \result;
*/
int foo116(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (min <= max + 1);
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || ((min >= \at(start,Pre)) && (max <= \at(end,Pre)) && (min <= max + 1)));
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> (((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || ((min >= \at(start,Pre)) && (max <= \at(end,Pre)) && (min <= max + 1)));
          loop invariant (!(\at(start,Pre) <= \at(end,Pre))) ==> ((max == \at(end,Pre))&&(min == \at(start,Pre))&&(end == \at(end,Pre))&&(start == \at(start,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant end == \at(end,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant same_array{Pre,Here}(array, \at(array_len,Pre)) ;
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
