/*@
    requires n >= 0;
    ensures \result > n;
    ensures \exists integer k; k * k == \result;
    assigns \nothing;
*/
int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /*@
        loop invariant i > 0;
        loop invariant square == (i-1) * (i-1);
        loop invariant square <= n;
        loop assigns i, square;
        loop variant n - square;
        */
        while (square <= n) {
            square = i * i;
            i++;
        }
        return square;
}
