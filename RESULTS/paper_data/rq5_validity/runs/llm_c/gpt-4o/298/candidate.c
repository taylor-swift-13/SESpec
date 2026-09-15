/*@
    requires \valid(a + (0..a_len-1));
    requires 0 <= leftElement <= rightElement < a_len;
    ensures \result >= leftElement && \result <= rightElement + 1;
    ensures \forall integer k; leftElement <= k < \result ==> a[k] == k;
    ensures \result == rightElement + 1 || a[\result] != \result;
    assigns \nothing;
*/
int smallestMissing(int * a, int a_len, int leftElement, int rightElement) {

    int i = leftElement;
    int j = rightElement;
    /*@
        loop invariant leftElement <= i <= j + 1;
        loop invariant leftElement <= j < a_len;
        loop invariant \forall integer k; leftElement <= k < i ==> a[k] == k;
        loop assigns i, j;
        loop variant j - i + 1;
    */
    while (i <= j) {
        int mid = (i + j) / 2;
        if (a[mid] == mid) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return i;
}
