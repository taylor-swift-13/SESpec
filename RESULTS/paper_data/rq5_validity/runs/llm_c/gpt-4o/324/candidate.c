/*@
    requires number >= 0;
    ensures \result >= 0 && \result <= 9;
    assigns \nothing;
*/
int firstDigit(int number);

int firstDigit(int number) {

    int first = 1;
    /*@
        loop invariant 1 <= c <= number + 1;
        loop invariant first == \product(1, c - 1, \lambda integer k; k);
        loop assigns c, first;
        loop variant number - c;
    */
    for (int c = 2; c <= number; c++) {
        first *= c;
    }

    int result = 0;
    /*@
        loop invariant first >= 0;
        loop invariant result >= 0 && result <= 9;
        loop assigns first, result;
        loop variant first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }
    return result;
}
