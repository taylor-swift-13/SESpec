int rightInsertion(int * a, int a_len, int x);

/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid(a + (0 .. a_len-1));
    requires \forall integer u, v; 0 <= u <= v < a_len ==> a[u] <= a[v];
    assigns \nothing;

    behavior exists_equal:
        assumes \exists integer k; 0 <= k < a_len && a[k] == x;
        ensures 0 <= \result < a_len;
        ensures a[\result] == x;

    behavior no_equal:
        assumes \forall integer k; 0 <= k < a_len ==> a[k] != x;
        ensures 0 <= \result <= a_len;
        ensures \forall integer k; 0 <= k < \result ==> a[k] < x;
        ensures \forall integer k; \result <= k < a_len ==> a[k] > x;

    complete behaviors exists_equal, no_equal;
    disjoint behaviors exists_equal, no_equal;
*/
int rightInsertion(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant -1 <= j <= a_len - 1;
            loop invariant \forall integer k; 0 <= k < i ==> a[k] < x;
            loop invariant \forall integer k; j < k < a_len ==> a[k] > x;
            loop assigns i, j;
            loop variant j - i + 1;
        */
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}
