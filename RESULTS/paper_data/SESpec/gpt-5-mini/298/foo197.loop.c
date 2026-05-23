
/*@
  predicate in_bounds(integer lo, integer hi, integer x) =
    lo <= x <= hi;
*/

int foo197(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant (!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==>
            ((j == \at(rightElement,Pre)) && (i == \at(leftElement,Pre)) &&
             (rightElement == \at(rightElement,Pre)) && (leftElement == \at(leftElement,Pre)) &&
             (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)));
          loop invariant rightElement == \at(rightElement,Pre);
          loop invariant leftElement == \at(leftElement,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop assigns i, j;
        */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            
        return i;
}
