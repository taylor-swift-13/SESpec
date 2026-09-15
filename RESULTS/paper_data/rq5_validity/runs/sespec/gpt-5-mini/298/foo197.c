
/*@
  predicate in_bounds(integer lo, integer hi, integer x) =
    lo <= x <= hi;
*/

/*@
  requires \valid(a + (0 .. a_len - 1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] && a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires leftElement <= rightElement + 1;
  assigns \nothing;
  ensures \result >= \old(leftElement) && \result <= \old(rightElement) + 1;
  ensures \forall integer k; \old(leftElement) <= k < \result ==> a[k] == \at(a,Pre)[k];
  ensures \forall integer k; \result <= k <= \old(rightElement) ==> a[k] == \at(a,Pre)[k];
  ensures a == \at(a,Pre) && a_len == \old(a_len) && leftElement == \old(leftElement) && rightElement == \old(rightElement);
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
          loop invariant leftElement <= i;
          loop invariant i <= rightElement + 1;
          loop invariant leftElement - 1 <= j && j <= rightElement;
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
