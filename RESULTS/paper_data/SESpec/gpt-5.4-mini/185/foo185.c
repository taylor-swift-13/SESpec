
/*@
  requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
  assigns \nothing;
  ensures 0 <= \result < a_len ==> a[\result] == x;
  ensures 0 <= \result < a_len ==> (\result == 0 || a[\result - 1] != x);
  ensures 0 <= \result < a_len ==> \forall integer i; 0 <= i < \result ==> a[i] <= x;
  ensures 0 <= \result < a_len ==> \forall integer i; \result < i < a_len ==> a[i] >= x;
  ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] <= x || a[i] >= x;
  ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] <= x || a[i] >= x;
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result == -1 || a[\result] == x;
*/
int foo185(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        
            
        /*@
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high < a_len;
          loop invariant low <= high + 1;
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
          loop invariant (low <= high) ==> (\forall integer k; low <= k <= high ==> (a[k] == x || a[k] < x || a[k] > x));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (low <= high + 1);
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= low <= a_len));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= high < a_len));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((high == \at(a_len,Pre) - 1)&&(low == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
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
