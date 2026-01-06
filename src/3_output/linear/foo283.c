
void foo283() {
    int x;
    int y;

    x = 0;
    y = 0;

    /*@
      loop invariant x == 4 * y;
      loop invariant y >= 0;
      loop invariant x >= 0;
      loop invariant x % 4 == 0;
      loop assigns x, y;
    */
    while (unknown()) {
       x += 4;
       y++;
    }

    /*@ assert x == 4 * y; */
}
