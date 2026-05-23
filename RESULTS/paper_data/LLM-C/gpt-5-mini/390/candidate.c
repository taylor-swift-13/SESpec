int permutationCoefficient(int n, int k);

/*@
    requires n >= 0 && 0 <= k <= n;
    assigns \nothing;
    ensures \result == (\product integer j; 1 <= j <= k; n - j + 1);
*/
int permutationCoefficient(int n, int k) {

        int res = 1;
        int i = 1;
        /*@
            loop invariant 1 <= i <= k + 1;
            loop invariant res == (\product integer j; 1 <= j <= i-1; n - j + 1);
            loop assigns i, res;
            loop variant k - i + 1;
        */
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
