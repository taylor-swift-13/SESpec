/*@
    requires number > 0;
    ensures \result >= 0;
    ensures \result == \sum(1, number / 2, \lambda integer i; (number % i == 0) ? i : 0);
    assigns \nothing;
*/
int sumDiv(int number) {

        int sum = 0;
        /*@
            loop invariant 1 <= i <= number / 2 + 1;
            loop invariant sum == \sum(1, i - 1, \lambda integer j; (number % j == 0) ? j : 0);
            loop assigns i, sum;
            loop variant number / 2 - i + 1;
        */
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}
