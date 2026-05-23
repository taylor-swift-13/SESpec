/*@ 
    requires a_len >= 0;
    requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures a_len == 0 ==> \result == -1;
    ensures a_len > 0 ==> (\exists integer i; 0 <= i < a_len && \result == a[i]);
    ensures a_len > 0 ==> \forall integer i; 0 <= i < a_len ==> \result <= a[i];
*/
int minElementInArray(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant \forall integer j; 0 <= j < i ==> res <= a[j];
            loop assigns i, res;
            loop variant a_len - i;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
}
