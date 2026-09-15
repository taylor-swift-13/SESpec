
/*@
requires a_len >= 0;
requires \valid_read(a + (0 .. a_len - 1));
requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
ensures \result == -1 || (0 <= \result < a_len && a[\result] == x && (\result == a_len - 1 || a[\result + 1] != x));
*/

int foo182(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        
        /*@
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high < a_len;
          loop invariant low <= high + 1;
          loop assigns low, high, mid;
        */
        while (low <= high) {
            mid = (low + high) / 2;
            /*@ assert low <= mid <= high; */
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
