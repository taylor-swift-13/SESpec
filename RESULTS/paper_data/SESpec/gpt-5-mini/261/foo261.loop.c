
/*@
  requires \valid_read(a + (0 .. a_len-1));
  requires a_len >= 0;
*/
        
int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant -1 <= j <= a_len - 1;
          loop invariant i <= j + 1;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] < x;
          loop invariant \forall integer k; j < k && k < a_len ==> a[k] > x;
          loop invariant (i <= j) ==> (\forall integer k; i <= k && k <= j ==> a[k] != x);
          loop assigns i, j, mid;
          */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            
        return i;
}
