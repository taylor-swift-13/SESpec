
/*@
  // No additional predicates or logic functions are required for these invariants.
*/

int foo174(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant -1 <= end < \at(a_len,Pre);
          loop invariant 0 <= start <= end + 1;
          loop invariant 0 <= start ==> start <= \at(a_len,Pre);
          loop assigns start, end;
            */
            while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && a[mid] > a[mid + 1]) {
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                return mid;
            }
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
            
        return 0;
}
