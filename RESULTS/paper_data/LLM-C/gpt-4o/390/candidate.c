/*@
    requires n >= 0;
    requires k >= 0;
    ensures \result == \prod(integer i = 0; i < k; n - i);
    assigns \nothing;
*/
int permutationCoefficient(int n, int k);

int permutationCoefficient(int n, int k) {

        int res = 1;
        int i = 1;
        /*@
            loop invariant 1 <= i <= k + 1;
            loop invariant res == \prod(integer j = 0; j < i - 1; n - j);
            loop assigns i, res;
            loop variant k - i + 1;
        */
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
