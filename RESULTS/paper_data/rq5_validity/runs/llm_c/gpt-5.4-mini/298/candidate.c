/*@
    requires a_len > 0;
    requires \valid_read(a + (0 .. a_len - 1));
    requires 0 <= leftElement <= rightElement < a_len;
    requires \forall integer k; leftElement <= k < rightElement ==> a[k] <= a[k + 1];
    requires \forall integer k; leftElement <= k <= rightElement ==> 0 <= a[k] < a_len;
    assigns \nothing;
    ensures leftElement <= \result <= rightElement + 1;
    ensures \forall integer k; leftElement <= k < \result ==> a[k] == k;
    ensures \result == rightElement + 1 || a[\result] != \result;
*/
int smallestMissing(int * a, int a_len, int leftElement, int rightElement);

int smallestMissing(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        /*@
            loop invariant leftElement <= i <= rightElement + 1;
            loop invariant leftElement - 1 <= j <= rightElement;
            loop invariant \forall integer k; leftElement <= k < i ==> a[k] == k;
            loop invariant \forall integer k; j < k <= rightElement ==> a[k] != k;
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
