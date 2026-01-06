
void foo66(int y) {
    int x = 1;
    
    /*@
      loop invariant ((x == 1) && (y == \at(y,Pre))) || (y == 100 - (x - 1));
      loop invariant 1 <= x <= 101;
      loop assigns x, y;
    */
    while (x <= 100) {
        y = 100 - x;
        x = x + 1;
    }

    /*@ assert (y < 100); */
}
