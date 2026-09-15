int permutationCoefficient(int n, int k);

int permutationCoefficient(int n, int k) {

        int res = 1;
        int i = 1;
        /*@
        loop invariant i <= k + 1;
        loop invariant 1 <= res;
        loop invariant 1 <= i;
        loop invariant 0 <= k;
        loop invariant res == \product(integer j = 1, i - 1) (n - j + 1);
        loop invariant res == \product(1, i-1, \lambda integer t; n - t + 1);
        loop invariant res == \product(integer j = 1, i - 1) (n - j + 1);
        loop invariant res == \product(1, i-1, \lambda integer t; n - t + 1);
        loop invariant res == \product(1, i - 1, \lambda integer t; n - t + 1);
        loop invariant res == \prod(integer t, 1, i-1, n - t + 1);
        loop invariant res == \prod(integer j, 1, i - 1, n - j + 1);
        loop invariant res == \prod(integer j = 1; j < i; j) (n - j + 1);
        loop invariant res == \prod(1, i - 1, \lambda integer t; n - t + 1);
        loop invariant res == (\product integer t; 1 <= t < i; n - t + 1);
        loop invariant i <= k + 1;
        loop invariant 1 <= res;
        loop invariant 1 <= i;
        loop invariant 0 <= k;
        loop assigns res;
        loop assigns i;
        */
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
