/*@
    requires l <= r;
    assigns \nothing;
    ensures \result == (\sum integer i; l <= i <= r && i % 2 != 0; i);
*/
int sumInRange(int l, int r);

 /*@
    requires l <= r;
    assigns \nothing;
    ensures \result == (\sum integer i; l <= i <= r && i % 2 != 0; i);
*/
int sumInRange(int l, int r) {

        int sum = 0;
        /*@
            loop invariant l <= i <= r + 1;
            loop invariant sum == (\sum integer j; l <= j < i && j % 2 != 0; j);
            loop assigns i, sum;
            loop variant r - i + 1;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
}
