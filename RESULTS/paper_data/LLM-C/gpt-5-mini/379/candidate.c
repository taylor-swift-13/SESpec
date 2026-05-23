int sumEven(int l, int r);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == \sum(j = l .. r, (j % 2 == 0 ? j : 0));
*/
int sumEven(int l, int r) {

        int sum = 0;
        /*@
            loop invariant i >= l;
            loop invariant i <= r+1 || l > r;
            loop invariant sum == \sum(j = l .. i-1, (j % 2 == 0 ? j : 0));
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
