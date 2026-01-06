
void foo84(int y) {
    int x = -50;
    
    /*@
      loop invariant y >= \at(y, Pre) && (y > 0 || x < 0);
      loop assigns x, y;
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
    
    /*@ assert y > 0; */
}
