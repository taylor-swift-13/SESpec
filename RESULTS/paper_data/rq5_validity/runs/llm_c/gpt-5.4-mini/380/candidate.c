/*@
    requires number >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int sumDiv(int number);

 /*@
    requires number >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int sumDiv(int number) {

        int sum = 0;
        /*@
            loop invariant 1 <= i <= number / 2 + 1;
            loop invariant sum >= 0;
            loop assigns i, sum;
            loop variant (number / 2 + 1) - i;
        */
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}
