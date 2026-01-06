
/*@
    requires x < y && y <= 20000001;
*/
void foo281(int x, int y) {
    /*@
        loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x == \at(x,Pre) + 100 * (\at(x,Here) - \at(x,Pre))/100) && (x <= y + 99);
        loop invariant (!(\at(x,Pre) < \at(y,Pre))) ==> ((y == \at(y,Pre)) && (x == \at(x,Pre)));
        loop invariant y == \at(y,Pre);
        loop assigns x;
    */
    while (x < y) {
        x = x + 100;
    }

    /*@ assert x <= y + 99; */
}
