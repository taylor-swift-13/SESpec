/*@
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len - 1));
    requires \forall integer i, j; 0 <= i < j < a_len ==> a[i] <= a[j];
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < a_len && a[\result] == x);
    ensures \result != -1 ==> (\result == a_len - 1 || a[\result + 1] != x);
    ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] != x;
*/
int findLastOccurrence(int * a, int a_len, int x);

int findLastOccurrence(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        /*@
            loop invariant 0 <= low <= a_len;
            loop invariant -1 <= high < a_len;
            loop invariant low <= high + 1;
            loop invariant \forall integer i; 0 <= i < low ==> a[i] < x;
            loop invariant \forall integer i; high < i < a_len ==> a[i] > x || a[i] == x;
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
