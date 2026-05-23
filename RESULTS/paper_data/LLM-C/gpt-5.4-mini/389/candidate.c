/*@
    requires q != 0;
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int findNthDigit(int p, int q, int n);

 /*@
    requires q != 0;
    requires n >= 0;
    assigns \nothing;
*/
int findNthDigit(int p, int q, int n) {

        int res = 0;
        /*@
            loop invariant n >= 0;
            loop invariant q != 0;
            loop assigns n, p, res;
            loop variant n;
        */
        while (n > 0) {
            n -= 1;
            p *= 10;
            res = p / q;
            p %= q;
        }
        return res;
}
