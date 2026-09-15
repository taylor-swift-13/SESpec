/*@
    requires n >= 0;
    requires k >= 0;
    requires k <= n;
    ensures \result >= 0;
    ensures \result == \binomial(n, k);
*/
int binomialCoeff(int n, int k);

int binomialCoeff(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        /*@
            loop invariant 1 <= i <= k + 1;
            loop invariant c == \product(j=1, i-1, (n-j+1)/j);
            loop assigns i, c;
            loop variant k - i + 1;
        */
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}
