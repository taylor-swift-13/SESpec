
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires a_len >= 0;
  requires \valid(a + (0 .. a_len - 1));
  requires \forall integer i,j; 0 <= i <= j < a_len ==> a[i] <= a[j];
  assigns \nothing;
  ensures \result >= 0 ==> 0 <= \result < a_len;
  ensures \result >= 0 ==> a[\result] == x;
  ensures \result >= 0 ==> (\result == a_len - 1 || a[\result + 1] != x);
*/
int foo182(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        
        /*@
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high < a_len;
          loop invariant low <= high + 1;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant (low <= high) ==> (low <= (low + high) / 2 <= high);
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
