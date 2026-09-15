
/*@ predicate all_between(int *a, integer lo, integer hi) =
      lo > hi ? \true :
      (a[lo] == lo && all_between(a, lo + 1, hi));
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (\result == i && \at(leftElement,Pre) <= \result <= \at(rightElement,Pre) + 1);
  ensures (!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==> (\result == \at(leftElement,Pre));
  ensures \forall integer k; \at(leftElement,Pre) <= k < \result ==> a[k] == k;
  ensures \forall integer k; \result <= k <= \at(rightElement,Pre) ==> (k >= \at(leftElement,Pre) && k < a_len ==> a[k] != k);
*/
int foo197(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (i == leftElement && j == rightElement));
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (j == rightElement && i == leftElement));
          loop invariant (!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==> ((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant rightElement == \at(rightElement,Pre);
          loop invariant leftElement == \at(leftElement,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \at(leftElement,Pre) <= i <= \at(rightElement,Pre) + 1;
          loop invariant \at(leftElement,Pre) - 1 <= j <= \at(rightElement,Pre);
          loop invariant i <= j + 1;
          loop invariant \forall integer k; \at(leftElement,Pre) <= k < i ==> a[k] == k;
          loop invariant \forall integer k; j < k <= \at(rightElement,Pre) ==> a[k] != k;
          loop assigns mid, i, j;
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
