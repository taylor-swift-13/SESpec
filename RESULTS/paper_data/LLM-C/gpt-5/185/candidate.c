int findFirstOccurrence(int * a, int a_len, int x);

/*@ 
  requires a_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len-1));
  requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];

  assigns \nothing;

  ensures \result == -1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] != x);
  ensures \result != -1 ==> 
            0 <= \result < a_len &&
            a[\result] == x &&
            (\result == 0 || a[\result-1] < x) &&
            (\forall integer k; 0 <= k < \result ==> a[k] < x);
  ensures (\exists integer k; 0 <= k < a_len && a[k] == x) ==> \result != -1;
*/
int findFirstOccurrence(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        /*@
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high <= a_len - 1;
          loop invariant low <= high + 1;
          loop invariant \forall integer i; 0 <= i < low ==> a[i] < x;
          loop invariant \forall integer i; high + 1 <= i < a_len ==> a[i] >= x;
          loop assigns low, high;
          loop variant high - low + 1;
        */
        while (low <= high) {
            int mid = low + (high - low) / 2;
            //@ assert low <= mid <= high;
            //@ assert 0 <= mid < a_len || a_len == 0 ==> (0 <= mid < a_len);
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
