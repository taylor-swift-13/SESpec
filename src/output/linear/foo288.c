
/*@
    requires x < y && y <= 20000001;
    */
    
void foo288(int x, int y) {

        /*@
          loop invariant (\at(x,Pre) < \at(y,Pre)) ==> (x < y ==> y - x <= \at(y,Pre) - \at(x,Pre) + 3);
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

    /*@ assert x >= y; */
}
