
/*@ predicate nondecreasing{L}(int *a, integer n) =
      \forall integer i,j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires a_len > 0 && a_len < 100;
  requires \valid_read(a + (0..a_len-1));
  requires nondecreasing(a, a_len);
  assigns \nothing;
  ensures (0 <= \result < a_len ==> (a[\result] == x && (\result == 0 || a[\result - 1] != x)));
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result == -1 || a[\result] == x;
*/
int foo40_c185(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        
        /*@
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \valid_read(a + (0..a_len-1));
          loop invariant nondecreasing(a, a_len);
          loop invariant a_len > 0 && a_len < 100;
          loop invariant -1 <= high < a_len;
          loop invariant 0 <= low <= a_len;
          loop assigns high, low;
        */
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == x) {
                if (mid == 0 || a[mid - 1] != x) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return -1;
}
