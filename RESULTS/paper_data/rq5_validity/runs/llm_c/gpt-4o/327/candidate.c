/*@
    requires n >= 0;
    ensures \result >= 0 && \result <= 9;
    assigns \nothing;
*/
int firstDigit(int n) {

        int fact = 1;
        /*@
            loop invariant 1 <= fact <= \prod(1..i-1);
            loop invariant 2 <= i <= n+1;
            loop assigns fact, i;
            loop variant n - i;
        */
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }

        int firstDigit = 0;
        /*@
            loop invariant fact >= 0;
            loop invariant firstDigit >= 0 && firstDigit <= 9;
            loop assigns fact, firstDigit;
            loop variant fact;
        */
        while (fact > 0) {
            firstDigit = fact % 10;
            fact /= 10;
        }
        return firstDigit;
}
