int maxElementInArray(int * a, int a_len);

/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid(a + (0 .. a_len-1));
    assigns \nothing;
    behavior empty:
        assumes a_len == 0;
        ensures \result == -1;
    behavior non_empty:
        assumes a_len > 0;
        ensures \forall integer k; 0 <= k < a_len ==> \result >= a[k];
        ensures \exists integer k; 0 <= k < a_len && \result == a[k];
    complete behaviors empty, non_empty;
    disjoint behaviors empty, non_empty;
*/
int maxElementInArray(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant \forall integer j; 0 <= j < i ==> res >= a[j];
            loop invariant i > 0 ==> (\exists integer j; 0 <= j < i && res == a[j]);
            loop assigns i, res;
            loop variant a_len - i;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
        return res;
}
