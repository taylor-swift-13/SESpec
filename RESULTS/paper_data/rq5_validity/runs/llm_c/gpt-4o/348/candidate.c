/*@
    requires a > 0;
    requires n >= 0;
    requires l <= r;
    ensures \result == -1 || (l <= \result <= r && \forall integer i; l <= i < \result ==> i % a != 0 && \count(l, \result, a) == n);
    assigns \nothing;
*/
int countNo(int a, int n, int l, int r) {

        int count = 0;
        /*@
        loop invariant l <= i <= r + 1;
        loop invariant count >= 0;
        loop invariant count <= n;
        loop invariant \forall integer j; l <= j < i ==> (j % a != 0 ==> count > 0);
        loop assigns i, count;
        loop variant r - i;
        */
        for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
        return -1;
}
