
/*@
    requires x < y && y <= 20000001;
    */
    
void foo289(int x, int y) {

        /*@
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x >= \at(x,Pre) && y >= \at(y,Pre) - 10*(x - \at(x,Pre))/7);
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x - y <= (\at(x,Pre) - \at(y,Pre)) + 17*(x - \at(x,Pre))/7);
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x - y <= 16);
          loop invariant (!(\at(x,Pre) < \at(y,Pre))) ==> ((y == \at(y,Pre))&&(x == \at(x,Pre)));
          loop assigns x, y;
        */
        while (x < y) {
            if ((x < 0 && y < 0)){
                x = x + 7;
                y = y - 10;
            }
            else if ((x < 0 && y >= 0)){
                x = x + 7;
                y = y + 3;
            }
            else {
                x = x + 10;
                y = y + 3;
            }
        }

    /*@ assert x <= y + 16; */
}
