

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i0; 0 <= i0 < a_len ==> 0 <= a[i0] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures a == \at(a,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures leftElement == \at(leftElement,Pre);
  ensures rightElement == \at(rightElement,Pre);
  ensures \result >= leftElement - 1;
  ensures (leftElement <= rightElement) ==> (\result <= rightElement + 1);
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
*/
int foo298(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant rightElement == \at(rightElement,Pre);
          loop invariant leftElement == \at(leftElement,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant i >= \at(leftElement,Pre) - 1;
          loop invariant j <= \at(rightElement,Pre) + 1;
          loop invariant i <= j + 1;
          loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (i <= \at(rightElement,Pre) + 1 && j >= \at(leftElement,Pre) - 1);
          loop assigns i, j, mid;
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
