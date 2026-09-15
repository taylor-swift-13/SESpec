int findLastOccurrence(int * a, int a_len, int x);

/*@ 
  requires a_len >= 0;
  requires a_len == 0 || \valid(a+(0..a_len-1));
  requires \forall integer i; 1 <= i < a_len ==> a[i-1] <= a[i];
  assigns \nothing;
  ensures (\result == -1) ==> (\forall integer j; 0 <= j < a_len ==> a[j] != x);
  ensures (\result != -1) ==> (0 <= \result < a_len && a[\result] == x);
  ensures (\result != -1) ==> (\forall integer k; \result < k < a_len ==> a[k] != x);
  ensures (\exists integer j; 0 <= j < a_len && a[j] == x) ==> \result != -1;
  ensures (\forall integer j; 0 <= j < a_len && a[j] == x ==> j <= \result);
*/
int findLastOccurrence(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        /*@
          loop invariant 0 <= low <= a_len;
          loop invariant -1 <= high <= a_len - 1;
          loop invariant low <= high + 1;
          loop invariant \forall integer i; 0 <= i < low ==> a[i] <= x;
          loop invariant \forall integer i; high < i < a_len ==> a[i] > x;
          loop assigns low, high, mid;
          loop variant high - low + 1;
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
