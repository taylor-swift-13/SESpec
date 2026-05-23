
/*@ predicate fixed_prefix(int *a, integer lo, integer hi) =
      \forall integer k; lo <= k < hi ==> a[k] == k;
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a == \old(a);
  ensures a_len == \old(a_len);
  ensures leftElement == \old(leftElement);
  ensures rightElement == \old(rightElement);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]);
  ensures (leftElement > rightElement) ==> (\result == leftElement);
  ensures (leftElement <= rightElement) ==> (leftElement <= \result <= rightElement + 1);
  ensures \result == (leftElement > rightElement ? leftElement : \result);
*/
int foo298(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (\at(leftElement,Pre) <= i);
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (j <= \at(rightElement,Pre));
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (i <= j + 1);
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (i > j ==> (j + 1 == i));

          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (i >= \at(leftElement,Pre) && i <= \at(rightElement,Pre) + 1);
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (j >= \at(leftElement,Pre) - 1 && j <= \at(rightElement,Pre));
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (i >= \at(leftElement,Pre) && i <= \at(rightElement,Pre) + 1));
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (j >= \at(leftElement,Pre) - 1 && j <= \at(rightElement,Pre)));
          loop invariant (!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==> ((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant rightElement == \at(rightElement,Pre);
          loop invariant leftElement == \at(leftElement,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
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
