/*@
    requires num >= 0;
    ensures \result >= 0 && \result <= 9;
    assigns \nothing;
*/
int firstDigit(int num);

int firstDigit(int num) {

    int first = 1;
    /*@
        loop invariant 2 <= j <= num + 1;
        loop invariant first == \prod(integer k; 2 <= k < j; k);
        loop assigns j, first;
        loop variant num - j;
    */
    for (int j = 2; j <= num; j++) {
        first *= j;
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
