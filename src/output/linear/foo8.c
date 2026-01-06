
/*@
    requires x >= 0 && x <= 10 && y <= 10 && y >= 0;
*/
void foo8(int x, int y) {
    /*@
        loop invariant x == \at(x, Pre) + 10 * ((y - \at(y, Pre)) / 10);
        loop invariant y == \at(y, Pre) + 10 * ((x - \at(x, Pre)) / 10);
        loop invariant (y - \at(y, Pre)) == (x - \at(x, Pre));
        loop invariant (x - \at(x, Pre)) % 10 == 0;
        loop invariant (y - \at(y, Pre)) % 10 == 0;
        loop invariant x >= \at(x, Pre) && y >= \at(y, Pre);
        loop assigns x, y;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
    
    /*@ assert (y == 0) ==> (x != 20); */
}
