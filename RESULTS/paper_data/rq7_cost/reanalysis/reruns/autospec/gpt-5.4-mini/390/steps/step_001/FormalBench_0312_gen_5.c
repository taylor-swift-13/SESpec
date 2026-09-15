int permutationCoefficient(int n, int k);

int permutationCoefficient(int n, int k) {

        int res = 1;
        int i = 1;
        /*@
        loop invariant 1 <= i <= k + 1;
        loop invariant res == \product(1, i - 1, \lambda integer t; n - t + 1);
        loop assigns i;
        loop assigns res;
        */
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
