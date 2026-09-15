int binomialCoeff(int n, int k);

/*@
    requires 0 <= n;
    requires 0 <= k <= n;
    assigns \nothing;
    ensures \result * (\product integer i; 1 <= i <= \min(\old(k), \old(n) - \old(k)); i)
            == (\product integer i; 1 <= i <= \min(\old(k), \old(n) - \old(k)); \old(n) - i + 1);
    ensures \result >= 1;
*/
int binomialCoeff(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        /*@
            loop invariant 1 <= i <= k + 1;
            loop invariant c * (\product integer j; 1 <= j < i; j)
                           == (\product integer j; 1 <= j < i; n - j + 1);
            loop assigns i, c;
            loop variant k - i + 1;
        */
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}
