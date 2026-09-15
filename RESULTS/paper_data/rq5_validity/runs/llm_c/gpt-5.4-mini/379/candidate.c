/*@
    requires l <= r;
    assigns \nothing;
    ensures \result ==
        (\sum integer i; l <= i <= r && i % 2 == 0; i);
*/
int sumEven(int l, int r);

int sumEven(int l, int r) {

        int sum = 0;
        /*@
            loop invariant l <= i <= r + 1;
            loop invariant sum ==
                (\sum integer k; l <= k < i && k % 2 == 0; k);
            loop assigns i, sum;
            loop variant r - i + 1;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
}
