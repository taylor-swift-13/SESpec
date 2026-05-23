
/*@ 
  predicate unchanged_array{L1,L2}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(a[i],L2);
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures unchanged_array{Pre,Post}(array, array_len);
  ensures (\at(start,Pre) <= \at(end,Pre) ?
             (\result >= \at(start,Pre) && \result <= \at(end,Pre) + 1)
           :
             (\result == \at(start,Pre)));
  ensures \result == \at(\result,Post); 
*/
int foo116_c254(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(start,Pre) <= \at(end,Pre)) ==> ( \at(start,Pre) <= min && min <= \at(end,Pre) + 1 && \at(start,Pre) - 1 <= max && max <= \at(end,Pre) );
          loop invariant (!(\at(start,Pre) <= \at(end,Pre))) ==> (max == \at(end,Pre) && min == \at(start,Pre) && end == \at(end,Pre) && start == \at(start,Pre) && array_len == \at(array_len,Pre) && array == \at(array,Pre));
          loop invariant end == \at(end,Pre);
          loop invariant start == \at(start,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant unchanged_array{Pre,Here}(array, array_len);
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
