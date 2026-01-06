
/*@
    requires x >= 0 && x <= 10 && y <= 10 && y >= 0;
*/
void foo7(int x, int y) {
    /*@
        loop invariant x - y == \at(x, Pre) - \at(y, Pre);
        loop invariant x >= \at(x, Pre);
        loop invariant y >= \at(y, Pre);
        loop invariant (x == \at(x, Pre)) || (y != 0);
        loop assigns x, y;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
    /*@ assert (x == 20) ==> (y != 0); */
}
