
/*@
predicate sorted{L}(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@ requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len - 1));
    requires sorted(a, a_len);
*/
int foo262(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
            /*@
          loop invariant 0 <= left <= a_len;
          loop invariant -1 <= right < a_len;
          loop invariant left <= right + 1;
          loop assigns left, right;
            */
            while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
            
        return left;
}
