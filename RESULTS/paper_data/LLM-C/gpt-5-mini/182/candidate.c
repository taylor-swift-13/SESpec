int findLastOccurrence(int * a, int a_len, int x);

/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid(a + (0 .. a_len-1));
    requires \forall int i; 0 <= i < a_len-1 ==> a[i] <= a[i+1];
    assigns \nothing;
    ensures (\result == -1) <==> (\forall int i; 0 <= i < a_len ==> a[i] != x);
    ensures (0 <= \result && \result < a_len) ==> (a[\result] == x &&
              (\forall int k; \result < k < a_len ==> a[k] != x));
*/
int findLastOccurrence(int * a, int a_len, int x) {

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
        /*@
            loop invariant 0 <= low <= a_len;
            loop invariant -1 <= high < a_len;
            loop invariant \forall int k; 0 <= k < a_len && a[k] == x ==> low <= k <= high;
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
