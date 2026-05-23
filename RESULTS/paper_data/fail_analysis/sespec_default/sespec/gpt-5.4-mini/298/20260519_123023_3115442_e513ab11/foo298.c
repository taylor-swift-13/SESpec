

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires leftElement <= rightElement + 1;
  requires \forall integer k; leftElement <= k < rightElement + 1 ==> 0 <= k < a_len;
  assigns \nothing;
*/
int foo298(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
        /*@
          loop invariant leftElement == \at(leftElement,Pre);
          loop invariant rightElement == \at(rightElement,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant i >= \at(leftElement,Pre);
          loop invariant j <= \at(rightElement,Pre);
          loop invariant \at(leftElement,Pre) > \at(rightElement,Pre) ==> i == \at(leftElement,Pre) && j == \at(rightElement,Pre);
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
