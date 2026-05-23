int leftInsertion(int * a, int a_len, int x);

/*@
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    requires \forall integer i; 0 <= i < a_len-1 ==> a[i] <= a[i+1];
    assigns \nothing;
    ensures 0 <= \result <= a_len;
    ensures (\exists integer k; 0 <= k < a_len && a[k] == x) ==> (0 <= \result < a_len && a[\result] == x);
    ensures (\forall integer k; 0 <= k < a_len ==> a[k] != x) ==>
            (\forall integer k; 0 <= k < \result ==> a[k] < x) &&
            (\forall integer k; \result <= k < a_len ==> a[k] > x);
*/
int leftInsertion(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        /*@
            loop invariant 0 <= left <= a_len;
            loop invariant -1 <= right < a_len;
            loop invariant left <= right + 1;
            loop invariant (\forall integer k; 0 <= k < left ==> a[k] < x);
            loop invariant (\forall integer k; right < k && k < a_len ==> a[k] > x);
            loop assigns left, right;
            loop variant right - left + 1;
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
