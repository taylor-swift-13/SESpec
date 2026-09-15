
/*@ 
  predicate search_inv(int* a, integer n, integer x, integer lo, integer hi) =
    0 <= lo <= n && -1 <= hi < n &&
    (\forall integer i; 0 <= i < lo ==> a[i] < x) &&
    (\forall integer i; hi < i && i < n ==> a[i] > x);
*/

int foo182(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low && low <= \at(a_len,Pre)));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= high && high < \at(a_len,Pre)));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= mid && mid < \at(a_len,Pre)));
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
