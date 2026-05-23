/*@
    requires \valid(a + (0..a_len-1));
    requires a_len >= 0;
    ensures \result == -1 ==> a_len == 0;
    ensures a_len > 0 ==> \exists integer i; 0 <= i < a_len && \result == a[i];
    ensures a_len > 0 ==> \forall integer i; 0 <= i < a_len ==> \result >= a[i];
    assigns \nothing;
*/
int maxElementInArray(int * a, int a_len);

int maxElementInArray(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT32_MIN;
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant \exists integer j; 0 <= j < i && res == a[j];
            loop invariant \forall integer j; 0 <= j < i ==> res >= a[j];
            loop assigns i, res;
            loop variant a_len - i;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
        return res;
}
