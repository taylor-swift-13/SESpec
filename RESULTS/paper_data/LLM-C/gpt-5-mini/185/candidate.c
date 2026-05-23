int findFirstOccurrence(int * a, int a_len, int x);

/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid(a + (0 .. a_len-1));
    requires \forall integer i; 0 <= i < a_len-1 ==> a[i] <= a[i+1];
    assigns \nothing;
    ensures (\result == -1) <==> (\forall integer i; 0 <= i < a_len ==> a[i] != x);
    ensures \result >= 0 ==> (0 <= \result < a_len && a[\result] == x && (\result == 0 || a[\result-1] != x));
*/
int findFirstOccurrence(int * a, int a_len, int x) {

        int low = 0, high = a_len - 1;
        /*@
            loop invariant 0 <= low <= a_len;
            loop invariant -1 <= high <= a_len - 1;
            loop invariant low <= high + 1;
            loop invariant \forall integer i; 0 <= i < low ==> a[i] < x;
            loop invariant \forall integer i; high+1 <= i < a_len ==> a[i] >= x;
            loop assigns low, high;
            loop variant high - low + 1;
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
