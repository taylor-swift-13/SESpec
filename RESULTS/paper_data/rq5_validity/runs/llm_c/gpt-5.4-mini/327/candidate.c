/*@
    requires n >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 9;
*/
int firstDigit(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 9;
*/
int firstDigit(int n) {

        int fact = 1;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant fact > 0;
            loop assigns i, fact;
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int firstDigit = 0;
        /*@
            loop invariant fact >= 0;
            loop invariant 0 <= firstDigit <= 9;
            loop assigns fact, firstDigit;
            loop variant fact;
        */
        while (fact > 0) {
            firstDigit = fact % 10;
            fact /= 10;
        }
        return firstDigit;
}
