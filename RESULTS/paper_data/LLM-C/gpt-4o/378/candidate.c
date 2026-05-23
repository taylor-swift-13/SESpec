/*@
    requires l <= r;
    ensures \result == \sum(l <= i <= r && i % 2 != 0, i);
    assigns \nothing;
*/
int sumInRange(int l, int r) {

        int sum = 0;
        /*@
            loop invariant l <= i <= r + 1;
            loop invariant sum == \sum(l <= j < i && j % 2 != 0, j);
            loop assigns i, sum;
            loop variant r - i;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
}
