
/*@
    requires x < y && y <= 20000001;
*/
void foo291(int x, int y) {
    /*@
        loop invariant x >= \at(x,Pre);
        loop invariant y - x <= \at(y,Pre) - \at(x,Pre);
        loop invariant (!(\at(x,Pre) < \at(y,Pre))) ==> ((y == \at(y,Pre)) && (x == \at(x,Pre)));
        loop assigns x, y;
    */
    while (x < y) {
        if (x < 0) {
            x = x + 7;
        } else {
            x = x + 10;
        }
        if (y < 0) {
            y = y - 10;
        } else {
            y = y + 3;
        }
    }

    /*@ assert x >= y; */
}
