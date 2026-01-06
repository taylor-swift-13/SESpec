
int foo88(int x) {
    int lock = 1;
    int y = x + 1;

    /*@
      loop invariant (\at(x,Pre) != y) ==> (y >= \at(x,Pre) + 1);
      loop invariant (!(\at(x,Pre) != y)) ==> ((y == \at(x,Pre) + 1) && (lock == 1) && (x == \at(x,Pre)));
      loop invariant x != y ==> (lock == 0 || x == y || (lock == 1 && x == \at(x,Pre)));
      loop invariant lock == 1 || x != y;
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
