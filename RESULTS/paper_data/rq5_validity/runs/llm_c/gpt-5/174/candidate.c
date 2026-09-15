/*@ predicate strictly_inc{L}(int *a, integer l, integer r) =
      \forall integer i; l <= i < r ==> \at(a[i],L) < \at(a[i+1],L);
*/

/*@ predicate rotated_strict{L}(int *a, integer n) =
      n <= 1 ||
      (\exists integer p; 0 <= p < n &&
         strictly_inc{L}(a, p, n-1) &&
         strictly_inc{L}(a, 0, p-1) &&
         (p == 0 || \at(a[n-1],L) < \at(a[0],L)));
*/

/*@ predicate is_rotation_pivot{L}(int *a, integer n, integer p) =
      (n <= 1 && p == 0) ||
      (n > 1 && 0 <= p < n &&
         strictly_inc{L}(a, p, n-1) &&
         strictly_inc{L}(a, 0, p-1) &&
         (p == 0 || \at(a[n-1],L) < \at(a[0],L)));
*/

int findRotationCount(int * a, int a_len);

/*@ requires a_len >= 0;
    requires a_len == 0 || \valid_read(a + (0 .. a_len-1));
    requires rotated_strict{Pre}(a, a_len);
    assigns \nothing;
    ensures a_len == 0 ==> \result == 0;
    ensures a_len > 0 ==> 0 <= \result < a_len;
    ensures a_len > 0 ==> is_rotation_pivot{Pre}(a, a_len, \result);
    ensures a_len > 0 ==> \forall integer i; 0 <= i < a_len ==> a[\result] <= a[i];
*/
int findRotationCount(int * a, int a_len) {

        int start = 0;
        int end = a_len - 1;
        /*@ loop invariant 0 <= start <= a_len;
            loop invariant -1 <= end < a_len;
            loop invariant start > end || (0 <= start && end <= a_len - 1);
            loop invariant start <= end ==> (end - start + 1) > 0;
            loop assigns start, end;
            loop variant end - start + 1;
        */
        while (start <= end) {
            int mid = start + (end - start) / 2;
            //@ assert start <= mid <= end;
            //@ assert start <= end ==> 0 <= start && end <= a_len-1;
            //@ assert \valid_read(a + mid);
            if (mid < end && a[mid] > a[mid + 1]) {
                //@ assert \valid_read(a + (mid+1));
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                //@ assert \valid_read(a + (mid-1));
                return mid;
            }
            //@ assert \valid_read(a + start);
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
}
