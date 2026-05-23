
/*@
  predicate sorted(int *a, integer lo, integer hi) =
    \forall integer i, j; lo <= i <= j < hi ==> a[i] <= a[j];
*/

/*@
  requires \valid(a + (0 .. a_len-1));
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires sorted(a, 0, a_len);
  assigns \nothing;
  ensures \result >= -1 && \result < a_len;
  ensures (\result == -1) <==> (\forall integer i; 0 <= i < a_len; a[i] != x);
  ensures (\result != -1) ==> (0 <= \result < a_len && a[\result] == x &&
                              (\result == 0 || a[\result-1] != x));
*/
int foo185(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        
            
        /*@
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high < a_len;
          loop invariant low <= high + 1;
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (0 <= low && high <= \at(a_len,Pre) - 1);
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (low > 0 || high < \at(a_len,Pre) - 1));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (high < \at(a_len,Pre) - 1 || low > 0));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant sorted(a, 0, a_len);
          loop assigns low, high;
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
