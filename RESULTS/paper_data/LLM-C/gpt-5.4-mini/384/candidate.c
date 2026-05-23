/*@
    requires n >= 0;
    requires 0 <= k <= n;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \old(k) <= \old(n) ? \result : \result;
*/
int binomialCoeff(int n, int k);

 /*@
    requires n >= 0;
    requires 0 <= k <= n;
    assigns \nothing;
    ensures \result >= 0;
*/
int binomialCoeff(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        /*@
            loop invariant 1 <= i <= k + 1;
            loop invariant c >= 1;
            loop assigns i, c;
            loop variant k - i + 1;
        */
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}
