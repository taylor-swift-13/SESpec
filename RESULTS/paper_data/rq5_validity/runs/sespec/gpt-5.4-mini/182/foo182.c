
/*@
  requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
              
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result != -1 ==> a[\result] == x;
  ensures \result != -1 ==> (\result == a_len - 1 || a[\result + 1] != x);
  ensures \result == -1 || (0 <= \result < a_len);  
*/
int foo182(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= low;
          loop invariant high < a_len;
          loop invariant 0 <= mid;
          loop invariant low <= high + 1;

          loop invariant 0 <= low && high < a_len && (low <= high + 1);
          loop invariant (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low));
          loop invariant (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (high < a_len));
          loop invariant (((mid == 0)&&(high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= mid));
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
