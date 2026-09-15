/*@
    requires num > 0;
    ensures \result >= 0;
    ensures \result == \sum(1 <= c <= num, num % c == 0 ? 1 : 0);
*/
int divisor(int num) {

    int div = 0;
    /*@
        loop invariant 1 <= c <= num + 1;
        loop invariant div == \sum(1 <= k < c, num % k == 0 ? 1 : 0);
        loop assigns c, div;
        loop variant num - c;
    */
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            div++;
        }
    }
    return div;
}
