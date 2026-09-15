/*@
    requires number > 0;
    ensures \result >= 0;
    ensures \result == (\sum integer c; 1 <= c <= number && number % c == 0; 1);
    assigns \nothing;
*/
int divisor(int number) {

    int div = 0;
    /*@
        loop invariant 1 <= c <= number + 1;
        loop invariant div == (\sum integer i; 1 <= i < c && number % i == 0; 1);
        loop assigns c, div;
        loop variant number - c;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }
    return div;
}
