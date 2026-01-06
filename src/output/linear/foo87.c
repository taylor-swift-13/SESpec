
int foo87(int y) {
    int lock = 1;
    int x = y;

    /*@
      loop invariant (\at(y,Pre) != \at(y,Pre)) ==> (y == \at(y,Pre) + 1);
      loop invariant (\at(y,Pre) != \at(y,Pre)) ==> (((x == \at(y,Pre))&&(lock == 1)&&(y == \at(y,Pre))) || (lock == 0));
      loop invariant (\at(y,Pre) != \at(y,Pre)) ==> (((x == \at(y,Pre))&&(lock == 1)&&(y == \at(y,Pre))) || (x == \at(y,Pre)));
      loop invariant (!(\at(y,Pre) != \at(y,Pre))) ==> ((x == \at(y,Pre))&&(lock == 1)&&(y == \at(y,Pre)));
      loop assigns lock, x, y;
    */
    while (x != y) {
        if (unknown()) {
            lock = 1;
            x = y;
        } else {
            lock = 0;
            x = y;
            y = y + 1;
        }
    }
    
    /*@ assert lock == 1;*/
}
