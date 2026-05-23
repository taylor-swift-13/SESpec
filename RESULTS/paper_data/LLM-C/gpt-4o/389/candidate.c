/*@
    requires q > 0;
    requires n > 0;
    ensures \result >= 0 && \result < 10;
    assigns p, n;
*/
int findNthDigit(int p, int q, int n);

int findNthDigit(int p, int q, int n) {

        int res = 0;
        /*@
            loop invariant n >= 0;
            loop invariant res >= 0 && res < 10;
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
