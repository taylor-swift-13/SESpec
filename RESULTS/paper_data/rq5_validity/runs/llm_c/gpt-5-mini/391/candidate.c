int nextPerfectSquare(int n);

/*@
    requires n < 2147395600; // ensure next perfect square fits in int (46340^2 = 2147395600)
    assigns \nothing;
    ensures \exists integer k; k >= 1 && \result == k*k && (k-1)*(k-1) <= n < k*k;
*/
int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /*@
            loop invariant i >= 1;
            loop invariant square >= 0;
            loop invariant (square == i*i) || (square == (i-1)*(i-1));
            loop assigns i, square;
            loop variant n - square + 1;
        */
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
