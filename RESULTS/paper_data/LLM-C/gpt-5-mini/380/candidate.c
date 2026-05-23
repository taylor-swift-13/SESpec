int sumDiv(int number);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == (\sum integer j; 1 <= j <= number/2 && number % j == 0; j);
*/
int sumDiv(int number) {

        int sum = 0;
        /*@
            loop invariant 1 <= i <= number/2 + 1;
            loop invariant sum == (\sum integer j; 1 <= j < i && number % j == 0; j);
            loop assigns i, sum;
            loop variant number/2 - i + 1;
        */
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}
