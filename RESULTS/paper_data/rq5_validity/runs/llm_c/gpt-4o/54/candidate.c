/*@
    assigns x, y;
    ensures x >= 99;
*/
void foo228() {

    int x;
    int y;

    x = 0;

    /*@
        loop invariant 0 <= x <= 99;
        loop assigns x;
        loop variant 99 - x;
    */
    while (x < 99) {
        if (y % 2 == 0) {
            x = x + 2;
        } else {
            x = x + 1;
        }
    }
}
