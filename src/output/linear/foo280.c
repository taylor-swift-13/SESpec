
/*@
    requires x < y;
*/
void foo280(int x, int y) {
    /*@
        loop invariant (!(\at(x,Pre) < \at(y,Pre))) ==> ((y == \at(y,Pre)) && (x == \at(x,Pre)));
        loop invariant y == \at(y,Pre);
        loop assigns x;
    */
    while (x < y) {
        x = x + 100;
    }
    /*@ assert x >= y; */
}
