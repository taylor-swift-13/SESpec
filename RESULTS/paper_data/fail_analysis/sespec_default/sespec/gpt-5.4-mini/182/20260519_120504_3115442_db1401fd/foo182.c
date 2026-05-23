
/*@
  predicate all_eq(int* a, integer lo, integer hi, integer x) =
    lo > hi ||
    (lo == hi ? (a[lo] == x) :
      (all_eq(a, lo, hi - 1, x) && a[hi] == x));
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result == -1 || 0 <= \result < a_len;
*/
int foo182(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        
        /*@
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> ((low <= high + 1) && (0 <= low) && (high < \at(a_len,Pre)));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (low <= high + 1));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (high >= -1));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop assigns mid, low, high;
        */
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == x) {
                if (mid == a_len - 1 || a[mid + 1] != x) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return -1;
}
