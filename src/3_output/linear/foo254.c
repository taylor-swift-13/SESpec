
void foo254() {
    int x;
    int y;

    x = 1;
    y = 1;

    /*@
      loop invariant 1 <= x <= 100;
      loop invariant (x <= 50 ==> y == x) && (x > 50 ==> y == 100 - x);
      loop assigns x, y;
    */
    while (y > 0) {
        if (x < 50) {
            y++;
        } else {
            y--;
        }
        x = x + 1;
    }

    /*@ assert x == 100; */
}
