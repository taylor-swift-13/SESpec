
/*@
    requires x < y && y <= 20000001;
    */
    
void foo290(int x, int y) {

        /*@
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x <= y + 16);
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x >= \at(x,Pre));
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (y >= \at(y,Pre) - 10 || y <= \at(y,Pre) + 3);
          loop invariant (!(\at(x,Pre) < \at(y,Pre))) ==> ((y == \at(y,Pre))&&(x == \at(x,Pre)));
          loop assigns x, y;
        */
        while (x < y) {
            if (x < 0) {
                x = x + 7;
            }
            else {
                x = x + 10;
            }
            if (y < 0) {
                y = y - 10;
            }
            else {
                y = y + 3;
            }
        }

    /*@ assert x <= y + 16; */
}
