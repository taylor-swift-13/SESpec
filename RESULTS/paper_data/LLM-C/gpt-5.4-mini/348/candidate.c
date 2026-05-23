/*@
    requires a != 0;
    requires l <= r;
    requires n >= 0;
    assigns \nothing;
    ensures \result == -1 || (l <= \result <= r);
    ensures \result == -1 ==> (\forall integer i; l <= i <= r ==> (i % a == 0) || (n > (r - l + 1)));
*/
int countNo(int a, int n, int l, int r);

 /*@
    requires a != 0;
    requires l <= r;
    requires n >= 0;
    assigns \nothing;
    ensures \result == -1 || (l <= \result <= r);
*/
int countNo(int a, int n, int l, int r) {

        int count = 0;
        /*@
            loop invariant l <= i <= r + 1;
            loop invariant 0 <= count <= i - l + 1;
            loop invariant count == \numof(integer k, l <= k < i && k % a != 0);
            loop assigns i, count;
            loop variant r - i + 1;
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
