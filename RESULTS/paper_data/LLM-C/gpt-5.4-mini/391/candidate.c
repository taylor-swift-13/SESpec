/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= n;
    ensures \exists integer k; k >= 0 && \result == k * k;
    ensures \forall integer k; k >= 0 && k * k >= n ==> \result <= k * k;
*/
int nextPerfectSquare(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= n;
    ensures \exists integer k; k >= 0 && \result == k * k;
    ensures \forall integer k; k >= 0 && k * k >= n ==> \result <= k * k;
*/
int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /*@
            loop invariant i >= 1;
            loop invariant square >= 1;
            loop invariant \forall integer k; 1 <= k < i ==> k*k <= n;
            loop assigns i, square;
            loop variant n - square + 1;
        */
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
