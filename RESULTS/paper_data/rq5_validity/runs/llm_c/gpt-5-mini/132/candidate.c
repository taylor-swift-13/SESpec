int minElementInArray(int * a, int a_len);

/*@
    requires a_len >= 0;
    behavior empty:
        assumes a_len == 0;
        ensures \result == -1;
        assigns \nothing;
    behavior non_empty:
        assumes a_len > 0;
        requires \valid(a + (0 .. a_len-1));
        ensures \exists integer k; 0 <= k < a_len && \result == a[k];
        ensures \forall integer j; 0 <= j < a_len ==> a[j] >= \result;
        assigns \nothing;
    complete behaviors empty, non_empty;
    disjoint behaviors empty, non_empty;
*/
int minElementInArray(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant (i == 0 ==> res == \at(res, Pre));
            loop invariant (i > 0 ==> (\exists integer k; 0 <= k < i && res == a[k] &&
                                       (\forall integer j; 0 <= j < i ==> a[j] >= res)));
            loop assigns i, res;
            loop variant a_len - i;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
}
